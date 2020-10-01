#pragma once

#include <ostream>
#include <string>
#include <variant>

#include "TokenType.h"

using Literal = std::variant<int, float, std::string>;

class Token
{
public:
    Token(
        TokenType&& type,
        std::string&& lexeme,
        Literal literal,
        int line);
    virtual ~Token();
    TokenType GetType() const;
    std::string GetLexeme() const;
    Literal GetLiteral() const;
    int GetLine() const;
    friend std::ostream& operator<<(std::ostream& os, Token& token);
private:
    TokenType type;
    std::string lexeme;
    Literal literal;
    int line;
};