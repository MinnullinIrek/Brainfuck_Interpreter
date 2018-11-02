#ifndef MEMORY_H
#define MEMORY_H

#include <array>

class Memory ;

using byte = char;

const int count = 30000;

using MemType = std::array<byte, 30000>;

class MemoryIterator
{



    friend Memory;
    MemType &memory;
    MemType::iterator iterator;


private:
    MemType::iterator summ(int k) const;
    MemoryIterator(MemType &memory, MemType::iterator iterator );
public:
    MemoryIterator (const MemoryIterator& mem) = default;
    MemoryIterator operator++ ()  ;
    MemoryIterator operator-- ();
    char& operator* ();
    MemoryIterator operator + (int k) const ;
    MemoryIterator operator - (int k) const;
    MemoryIterator operator += (int k);
    MemoryIterator operator -= (int k);
    int getPosition() const;


    bool operator == (const MemoryIterator &mem) const;
    bool operator != (const MemoryIterator &mem) const;

    bool operator == (const byte ch);

};


class Memory
{

    MemType mem;
//     start = mem;

public:
    Memory() = default;
    ~Memory() = default;
    MemoryIterator begin();
    MemoryIterator end();
};

#endif // MEMORY_H
