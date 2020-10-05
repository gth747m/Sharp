#pragma once

#include <ostream>
#include <string>
#include <variant>

#include "Literal.hpp"
#include "TokenType.hpp"

class Token
{
public:
    Token(
        TokenType&& type,
        Literal literal,
        int line,
        int column);
    virtual ~Token();
    TokenType GetType() const;
    Literal GetLiteral() const;
    int GetLine() const;
    int GetColumn() const;
    friend std::ostream& operator<<(std::ostream& os, Token& token);
private:
    TokenType type;
    Literal literal;
    int line;
    int column;
};