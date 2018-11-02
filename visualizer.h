#ifndef VISUALIZER_H
#define VISUALIZER_H

class Memory;
class MemoryIterator;

class Visualizer
{
    const Memory &memory;
public:
    Visualizer(const Memory &memory);
    void show(const MemoryIterator &iterator, int count = 10)const ;

};

#endif // VISUALIZER_H
