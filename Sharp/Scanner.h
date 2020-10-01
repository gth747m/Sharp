#pragma once

#include <istream>
#include <sstream>
#include <vector>

#include "Token.h"

class Scanner
{
public:
    static std::vector<Token> ScanTokens(std::istream& stream);
    std::vector<Token> GetTokens() const;
protected:
    Scanner(std::istream& stream);
    virtual ~Scanner();
private:
    // Members
    char currChar;
    std::stringstream currString;
    int line;
    std::istream& stream;
    std::vector<Token> tokens;
    // Methods
    bool Match(char c);
    char Advance();
    char Peek();
    char PeekAgain();
    void AddToken(TokenType&& token);
    void AddToken(TokenType&& token, Literal literal);
    void ScanIdentifier();
    void ScanNumber();
    void ScanString();
    void ScanToken();
};