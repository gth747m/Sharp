#include "Token.hpp"

Token::Token(
    TokenType&& type,
    Literal literal,
    int line,
    int column) :
    type(std::move(type)),
    literal(literal),
    line(line),
    column(column)
{
}

Token::~Token()
{
}

TokenType Token::GetType() const
{
    return this->type;
}

Literal Token::GetLiteral() const
{
    return this->literal;
}

int Token::GetLine() const
{
    return this->line;
}

int Token::GetColumn() const
{
    return this->column;
}

std::ostream& operator<<(std::ostream& os, Token& token)
{
    os << "Token: " << std::endl;
    os << "      type: " << token.GetType() << std::endl;
    os << "   literal: " << token.GetLiteral();
    os << "      line: " << token.GetLine() << std::endl;
    os << "    column: " << token.GetColumn() << std::endl;
    return os;
}