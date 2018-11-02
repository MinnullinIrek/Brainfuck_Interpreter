#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <array>
#include <vector>

class Parser
{
    std::array<char, 8u> comms ;//= {'>', '<', '+',  '-', '[', ']',   '.', ','};
public:
    Parser();
    std::vector<std::pair<char, char>> parse(std::string &code);
    bool isCorrect(char c);
    std::pair<char, char> getEqualCommand(std::string::iterator &c, std::string::iterator &end);
};

#endif // PARSER_H
