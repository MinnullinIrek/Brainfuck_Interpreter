#include <cstring>
#include <string>

#include "memory.h"


MemoryIterator::MemoryIterator(MemType &memory, MemType::iterator iterator ):
    memory(memory),
    iterator(iterator)
{

}



int MemoryIterator::getPosition() const
{
    return iterator - memory.begin();
}






MemoryIterator MemoryIterator::operator++ ()
{
    this->iterator++;
    if(iterator - memory.begin() >= count ) {
        iterator = memory.begin();
    }
    return *this;
}

MemoryIterator MemoryIterator::operator-- ()
{
    if(iterator == memory.begin() ) {
        iterator = memory.end() - 1;
    } else {
        iterator--;
    }
    return *this;
}

byte& MemoryIterator::operator* ()
{
    return *iterator;
}

MemType::iterator MemoryIterator::summ(int k) const
{
    auto iterator = this->iterator;
    int curent = iterator - memory.begin();
    if(curent + k < count && curent + k >= 0){
        iterator += k;
    } else {
        int l = curent + k - count *(k/count);
        if(l >= 0) {
            iterator = memory.begin() + l;
        } else {
            iterator = memory.end() - 1 + l;
        }
    }

    return iterator;
}

MemoryIterator MemoryIterator::operator + (int k) const
{
    auto ch = summ(k);

    return  MemoryIterator(memory, ch);
}

MemoryIterator MemoryIterator::operator - (int k) const
{
    auto ch = summ(-k);
    return MemoryIterator(memory, ch);
}

MemoryIterator MemoryIterator::operator += (int k)
{
    iterator = summ(k);
    return *this;
}



MemoryIterator MemoryIterator::operator -= (int k)
{
    iterator = summ(-k);
    return *this;

}

MemoryIterator Memory::begin()
{
    return MemoryIterator(mem, mem.begin());
}

MemoryIterator Memory::end()
{
    return MemoryIterator(mem, mem.end());
}

bool MemoryIterator::operator == (const MemoryIterator &mem) const
{
    return mem.iterator == iterator;
}

bool MemoryIterator::operator != (const MemoryIterator &mem) const
{
    return mem.iterator != iterator;
}


bool MemoryIterator::operator == (const byte ch)
{
    return ch == *iterator;
}
