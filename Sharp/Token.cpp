#include "Token.h"

#include <iostream>

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

std::ostream& operator<<(std::ostream& os, Literal literal)
{
    return os;
}

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

std::ostream& operator<<(std::ostream& os, Token& token)
{
    os << "Token: " << std::endl;
    os << "      type: " << token.GetType() << std::endl;
    os << "   literal: ";
    Literal lit = token.GetLiteral();
    std::visit(overload{
            [&](int& intLit) {os << intLit << std::endl; },
            [&](int64_t& intLit) {os << intLit << std::endl; },
            [&](float& floatLit) {os << floatLit << std::endl; },
            [&](double& floatLit) {os << floatLit << std::endl; },
            [&](std::string& strLit) {os << "'" << strLit << "'" << std::endl; }
        }, lit);
    os << "      line: " << token.GetLine() << std::endl;
    os << "    column: " << token.GetColumn() << std::endl;
    return os;
}