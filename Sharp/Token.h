#pragma once

#include <ostream>
#include <string>
#include <variant>

#include "TokenType.h"

using Literal = std::variant<int, int64_t, float, double, std::string>;

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
    std::string text;
    Literal literal;
    int line;
    int column;
};