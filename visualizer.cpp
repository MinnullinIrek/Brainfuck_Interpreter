#include <iostream>

#include "visualizer.h"
#include "memory.h"


Visualizer::Visualizer(const Memory &memory):
    memory(memory)
{

}

void Visualizer::show(const MemoryIterator &iterator, int count ) const
{
    std::cout << "position:" << iterator.getPosition() << std::endl;
    MemoryIterator mem = (iterator - count/2);

    while ( mem != iterator + count/2 ) {

        if(mem == iterator)
            std::cout << " |" << static_cast<int>(*mem) << "| ";
        else
            std::cout << "|" << static_cast<int>(*mem) << "|";
        ++mem;
    }
    std::cout << std::endl;
}
