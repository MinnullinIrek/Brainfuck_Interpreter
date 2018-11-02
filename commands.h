#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <array>
#include <functional>

using byte = char;
using sint = char;


class Memory;
class MemoryIterator;

class Commands
{

public:
    Commands() = default;
    void exec(MemoryIterator &iterator, std::vector<std::pair<byte, sint>> &coms, std::function<void(const MemoryIterator &)> d);
};

#endif // COMMANDS_H
