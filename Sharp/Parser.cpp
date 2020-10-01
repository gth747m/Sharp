#include "Parser.h"

Parser::Parser() :
    currentLine(0),
    tokens(std::vector<Token>())
{
}

Parser::~Parser()
{
}
