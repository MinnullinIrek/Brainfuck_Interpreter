#include <vector>
#include "parser.h"

using byte = char;
using sint = char;


Parser::Parser():
    comms({'>', '<', '+',  '-', '[', ']',   '.', ','})
{

}

bool Parser::isCorrect(char command)
{
    for(auto c : comms) {
        if(c == command)
            return true;
    }
    return false;
}

std::pair<byte, sint> Parser::getEqualCommand(std::string::iterator &c, std::string::iterator & end)
{
    byte com = 0;
    sint k = 0;
    byte symb = *c;
    if(symb == '>' || symb == '<' || symb == '-' || symb == '+'){
        com = *c;
        sint delta = (symb == '<' || symb == '-') ? -1: 1;
        while (c != end && *c == symb) {
            k += delta;
            ++c;
        }

    } else
        if(symb == '.'){
            com = *c;
            ++c;
            k = 1;
        } else
            if(symb == ','){
                com = *c;
                ++c;
                k = 1;
            } else
                if(symb == '['){
                    if((*(c+1) == '-' || *(c+1) == '+') && *(c+2) == ']') {
                        com = '0';
                        k = 1;
                        c += 2;
                    } else
                    {
                        com = *c;
                        ++c;
                        k = 1;
                    }
                } else
                    if(symb == ']'){
                        com = *c;
                        ++c;
                        k = 1;
                    }

    return std::make_pair(com, k);
}

std::vector<std::pair<byte, sint>> Parser::parse(std::string &code)
{
    std::vector<std::pair<byte, sint>> commands;

    auto end = code.end();
    for (auto c = code.begin(); c != end; ) {
        if(isCorrect(*c)) {
            auto com = getEqualCommand(c, end);
            commands.push_back(com);
        }
    }

    return commands;
}
