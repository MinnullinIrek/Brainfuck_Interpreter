#include <iostream>
#include <cstddef>

#include "codegetter.h"
#include "parser.h"
#include "commands.h"
#include "memory.h"
#include "visualizer.h"

using namespace std;

int main(int argc, char** )
{
    CodeGetter getter;
    Parser parser;
    Commands command;
    Memory memory= {};
    Visualizer visualizer(memory);

    std::string code;
    if(argc == 1) {
        auto iterator = memory.begin();
        while(code != "exit"){
            code = getter.getCode();
            auto commands = parser.parse(code);
            command.exec(iterator,commands, [visualizer](const MemoryIterator &iterator){visualizer.show(iterator);});

        }


    }
    cout << "Brainfuck interpreter:" << endl;
    return 0;
}
