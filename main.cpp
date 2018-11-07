#include <iostream>
#include <cstddef>
#include <fstream>


#include "codegetter.h"
#include "parser.h"
#include "commands.h"
#include "memory.h"
#include "visualizer.h"

using namespace std;

void execCommand(string &&code);

int main(int argc, char** argv)
{
    CodeGetter getter;
    Parser parser;
    Commands command;
    Memory memory= {};
    auto iterator = memory.begin();

    Visualizer visualizer(memory);

    std::string code;

    auto exec = [&](string & code, std::function<void(const MemoryIterator&)> func)
    {
        auto commands = parser.parse(code);
        command.exec(iterator,commands, func);
    };

    if(argc == 1) {
        while(code != "exit"){
            code = getter.getCode();
            exec(code, [visualizer](const MemoryIterator &iterator){visualizer.show(iterator);});
        }
    }
    else {
        ifstream infile(argv[1]);
        if(!infile.is_open()) {
            cout << "There is no file " << argv[1]<< endl;
        }
        while(getline(infile, code));

        exec(code, [](const MemoryIterator &){});
    }


    return 0;
}

