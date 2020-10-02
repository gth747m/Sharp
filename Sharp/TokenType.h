#pragma once

#include <map>

enum class TokenType : int
{
    // Single character tokens

    /// <summary>
    /// Left parentheses (()
    /// </summary>
    LEFT_PAREN, 
    /// <summary>
    /// Right parentheses ())
    /// </summary>
    RIGHT_PAREN, 
    /// <summary>
    /// Left brace ({)
    /// </summary>
    LEFT_BRACE, 
    /// <summary>
    /// Right brace (})
    /// </summary>
    RIGHT_BRACE,
    /// <summary>
    /// Comma (,)
    /// </summary>
    COMMA, 
    /// <summary>
    /// Dot (.)
    /// </summary>
    DOT, 
    /// <summary>
    /// Minus (-)
    /// </summary>
    MINUS, 
    /// <summary>
    /// Plus (+)
    /// </summary>
    PLUS, 
    /// <summary>
    /// Colon (:)
    /// </summary>
    COLON, 
    /// <summary>
    /// Semicolon (;)
    /// </summary>
    SEMICOLON, 
    /// <summary>
    /// Slash (/)
    /// </summary>
    SLASH, 
    /// <summary>
    /// Star (*)
    /// </summary>
    STAR,
    /// <summary>
    /// Hash (#)
    /// </summary>
    HASH,

    // Comparison tokens

    /// <summary>
    /// Bang (!)
    /// </summary>
    BANG, 
    /// <summary>
    /// Bang equal (!=)
    /// </summary>
    BANG_EQUAL, 
    /// <summary>
    /// Equal (=)
    /// </summary>
    EQUAL, 
    /// <summary>
    /// Equal equal (==)
    /// </summary>
    EQUAL_EQUAL,
    /// <summary>
    /// Greater than (>)
    /// </summary>
    GREATER, 
    /// <summary>
    /// Greater than or equal (>=)
    /// </summary>
    GREATER_EQUAL, 
    /// <summary>
    /// Less than (<)
    /// </summary>
    LESS, 
    /// <summary>
    /// Less than or equal (<=)
    /// </summary>
    LESS_EQUAL,

    // Literals

    /// <summary>
    /// Identifier literal
    /// </summary>
    IDENTIFIER, 
    /// <summary>
    /// String literal
    /// </summary>
    STRING, 
    /// <summary>
    /// Number literal
    /// </summary>
    NUMBER,

    // Keywords

    /// <summary>
    /// and
    /// </summary>
    AND, 
    /// <summary>
    /// class
    /// </summary>
    CLASS, 
    /// <summary>
    /// else
    /// </summary>
    ELSE, 
    /// <summary>
    /// flase
    /// </summary>
    FALSE, 
    /// <summary>
    /// function
    /// </summary>
    FUNCTION, 
    /// <summary>
    /// for
    /// </summary>
    FOR, 
    /// <summary>
    /// foreach
    /// </summary>
    FOREACH, 
    /// <summary>
    /// if
    /// </summary>
    IF, 
    /// <summary>
    /// null
    /// </summary>
    NUL, 
    /// <summary>
    /// or
    /// </summary>
    OR,
    /// <summary>
    /// return
    /// </summary>
    RETURN, 
    /// <summary>
    /// super
    /// </summary>
    SUPER, 
    /// <summary>
    /// this
    /// </summary>
    THIS, 
    /// <summary>
    /// true
    /// </summary>
    TRUE, 
    /// <summary>
    /// var
    /// </summary>
    VAR, 
    /// <summary>
    /// while
    /// </summary>
    WHILE,
    /// <summary>
    /// void
    /// </summary>
    VOID
};

const std::map<TokenType, const char*> TokenTypeNameMap = {
    {TokenType::LEFT_PAREN, "LEFT_PAREN"},
    {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
    {TokenType::LEFT_BRACE, "LEFT_BRACE"},
    {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
    {TokenType::COMMA, "COMMA"},
    {TokenType::DOT, "DOT"},
    {TokenType::MINUS, "MINUS"},
    {TokenType::PLUS, "PLUS"},
    {TokenType::COLON, "COLON"},
    {TokenType::SEMICOLON, "SEMICOLON"},
    {TokenType::SLASH, "SLASH"},
    {TokenType::STAR, "STAR"},
    {TokenType::HASH, "HASH"},
    {TokenType::BANG, "BANG"},
    {TokenType::BANG_EQUAL, "BANG_EQUAL"},
    {TokenType::EQUAL, "EQUAL"},
    {TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
    {TokenType::GREATER, "GREATER"},
    {TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
    {TokenType::LESS, "LESS"},
    {TokenType::LESS_EQUAL, "LESS_EQUAL"},
    {TokenType::IDENTIFIER, "IDENTIFIER"},
    {TokenType::STRING, "STRING"},
    {TokenType::NUMBER, "NUMBER"},
    {TokenType::AND, "AND"},
    {TokenType::CLASS, "CLASS"},
    {TokenType::ELSE, "ELSE"},
    {TokenType::FALSE, "FALSE"},
    {TokenType::FUNCTION, "FUNCTION"},
    {TokenType::FOR, "FOR"},
    {TokenType::FOREACH, "FOREACH"},
    {TokenType::IF, "IF"},
    {TokenType::NUL, "NUL"},
    {TokenType::OR, "OR"},
    {TokenType::RETURN, "RETURN"},
    {TokenType::SUPER, "SUPER"},
    {TokenType::THIS, "THIS"},
    {TokenType::TRUE, "TRUE"},
    {TokenType::VAR, "VAR"},
    {TokenType::WHILE, "WHILE"},
};

inline std::ostream& operator<<(
    std::ostream& os, 
    TokenType type) 
{
    auto it = TokenTypeNameMap.find(type);
    if (it != TokenTypeNameMap.end())
        os << it->second;
    return os;
}
