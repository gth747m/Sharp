#pragma once

#include <vector>

#include "Token.hpp"

class Parser
{
public:
    Parser(std::vector<Token>&& tokens);
    virtual ~Parser() = default;
private:
    std::vector<Token> tokens;
    int currentLine;
};
