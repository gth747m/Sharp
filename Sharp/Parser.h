#pragma once

#include <vector>

#include "Token.h"

class Parser
{
public:
    Parser();
    virtual ~Parser();
private:
    std::vector<Token> tokens;
    int currentLine;
};
