#include "Token.h"

Token::Token(
    TokenType&& type,
    std::string&& lexeme,
    Literal literal,
    int line) :
    type(std::move(type)),
    lexeme(std::move(lexeme)),
    literal(literal),
    line(line)
{
}

Token::~Token()
{
}

TokenType Token::GetType() const
{
    return this->type;
}

std::string Token::GetLexeme() const
{
    return this->lexeme;
}

Literal Token::GetLiteral() const
{
    return this->literal;
}

int Token::GetLine() const
{
    return this->line;
}

std::ostream& operator<<(std::ostream& os, Literal literal)
{
    return os;
}

std::ostream& operator<<(std::ostream& os, Token& token)
{
    os << "Token: " << std::endl;
    os << "      type: " << token.GetType() << std::endl;
    os << "    lexeme: " << token.GetLexeme() << std::endl;
    os << "   literal: " << token.GetLiteral() << std::endl;
    os << "      line: " << token.GetLine() << std::endl;
    return os;
}