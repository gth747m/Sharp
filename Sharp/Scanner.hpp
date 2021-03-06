#pragma once

#include <istream>
#include <sstream>
#include <vector>

#include "Token.hpp"

class Scanner
{
public:
    static std::vector<Token> GetTokens(std::istream& stream);
protected:
    Scanner(std::istream& stream);
    virtual ~Scanner() = default;
private:
    // Member Variables
    int line;
    int column;
    std::istream& stream;
    std::vector<Token> tokens;
    // Member Methods
    bool Match(char c);
    char Advance();
    void AddToken(TokenType&& token);
    void AddToken(TokenType&& token, int lineStart, int columnStart);
    void AddToken(TokenType&& token, Literal literal);
    void AddToken(TokenType&& token, Literal literal, int lineStart, int columnStart);
    void PutBack(char c);
    void Scan();
    void ScanIdentifier(char c);
    void ScanNumber(char c);
    void ScanString();
    void ScanToken();
};