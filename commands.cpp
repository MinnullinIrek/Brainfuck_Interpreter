#include <iostream>
#include <functional>

#include "commands.h"
#include "memory.h"

//                 20                  40                  60                  80       90       100                   120
//34567890123456789A123456789B123456789c123456789d123456789e123456789f123456789g123456789h123456789j123456789k123456789l123456789
void Commands::exec(MemoryIterator &cell, std::vector<std::pair<byte, sint>> &coms, std::function<void(const MemoryIterator&)> d)
{
    for(auto command = coms.begin(); command < coms.end(); ++command) {
        const auto symb = command->first;

        if(symb == '>' || symb == '<'){
            cell += command->second;
        }else if(symb == '+' || symb == '-'){
            *cell += command->second;
        }else if(symb == '[') {

            if((*cell) == 0) {
                int brac = 1;
                ++command;
                while( command != coms.end() && brac) {
                    if(command->first == ']')
                        brac--;
                    else if(command->first == '[')
                        brac++;
                    ++command;
                }
            }
        } else if(symb == ']') {
            int brac = 1;
            --command;
            while( command != coms.end() && brac) {
                if(command->first == ']') {
                    brac++;
                } else if(command->first == '[') {
                    brac--;
                }
                --command;
            }
        } else if (symb == '0') {
            *cell = 0;
        }
        else if(symb == '.') {
            std::cout << *cell;
        }else if(symb == ',') {
            std::cin >> (*cell);
        }
    }

    d(cell);


}
