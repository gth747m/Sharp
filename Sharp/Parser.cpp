#include "Parser.hpp"

Parser::Parser(std::vector<Token>&& tokens) :
    currentLine(0),
    tokens(std::move(tokens))
{
}
