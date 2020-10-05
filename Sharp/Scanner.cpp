#include "Scanner.hpp"

#include <cctype>
#include <exception>
#include <iostream>
#include <map>

#include "ScanException.hpp"

static const std::map<const char *, TokenType> Keywords = 
    {
        {"AND", TokenType::AND},
        {"CLASS", TokenType::CLASS},
        {"ELSE", TokenType::ELSE},
        {"FALSE", TokenType::FALSE},
        {"FUN", TokenType::FUNCTION},
        {"FOR", TokenType::FOR},
        {"IF", TokenType::IF},
        {"NULL", TokenType::NUL},
        {"OR", TokenType::OR},
        {"RETURN", TokenType::RETURN},
        {"SUPER", TokenType::SUPER},
        {"THIS", TokenType::THIS},
        {"TRUE", TokenType::TRUE},
        {"VAR", TokenType::VAR},
        {"WHILE", TokenType::WHILE},
        {"VOID", TokenType::VOID}
    };

Scanner::Scanner(std::istream& stream) :
    line(1),
    column(0),
    stream(stream),
    tokens(std::vector<Token>())
{
}

Scanner::~Scanner()
{
}

std::vector<Token> Scanner::GetTokens(std::istream& stream)
{
    Scanner scanner = Scanner(stream);
    scanner.Scan();
    return scanner.tokens;
}

bool Scanner::Match(char c)
{
    if (this->stream.eof()) 
        return false;
    if (this->stream.peek() != c) 
        return false;
    this->Advance();
    return true;
}

char Scanner::Advance()
{
    if (this->stream.eof()) 
        return 0;
    this->column++;
    return (char)this->stream.get();
}

void Scanner::AddToken(TokenType&& token)
{
    this->AddToken(std::move(token), std::move(Literal()));
}

void Scanner::AddToken(TokenType&& token, int lineStart, int columnStart)
{
    this->AddToken(std::move(token), std::move(Literal()), lineStart, columnStart);
}

void Scanner::AddToken(TokenType&& token, Literal literal)
{
    this->tokens.push_back(Token(std::move(token), 
        literal, line, column));
}

void Scanner::AddToken(TokenType&& token, Literal literal, int lineStart, int columnStart)
{
    this->tokens.push_back(Token(std::move(token), 
        literal, lineStart, columnStart));
}

void Scanner::PutBack(char c)
{
    this->stream.putback(c);
    this->column--;
}

void Scanner::Scan()
{
    while (!this->stream.eof()) {
        this->ScanToken();
    }
}

void Scanner::ScanIdentifier(char c)
{
    char currChar = c;
    int lineStart = this->line;
    int columnStart = this->column;
    std::stringstream ssOrig;
    std::stringstream ssUpper;
    while (isalnum(currChar) || currChar == '_')
    {
        ssOrig << currChar;
        ssUpper << toupper(currChar);
        currChar = Advance();
    }
    this->PutBack(currChar);
    auto it = Keywords.find(ssUpper.str().c_str());
    if (it == Keywords.end())
    {
        this->AddToken(TokenType::IDENTIFIER, 
            ssOrig.str().c_str(), lineStart, columnStart);
    }
    else 
    {
        TokenType type = it->second;
        this->AddToken(std::move(type), lineStart, columnStart);
    }
}

void Scanner::ScanNumber(char c)
{
    char currChar = c;
    int lineStart = this->line;
    int columnStart = this->column;
    std::stringstream ss;
    while (isdigit(currChar) || currChar == ',' || currChar == '.')
    {
        ss << currChar;
        currChar = Advance();
    }
    this->PutBack(currChar);
    this->AddToken(TokenType::NUMBER, 
        Literal(ss.str().c_str()), lineStart, columnStart);
}

void Scanner::ScanString()
{
    int lineStart = this->line;
    int columnStart = this->column;
    char currChar = this->Advance();
    std::stringstream ss;
    while (currChar != '"' && !this->stream.eof())
    {
        ss << currChar;
        currChar = this->Advance();
    }
    if (this->stream.eof())
    {
        throw ScanException("Unterminated string.", lineStart, columnStart);
    }
    this->AddToken(TokenType::STRING, 
        Literal(ss.str().c_str()), lineStart, columnStart);
}

void Scanner::ScanToken()
{
    char c = this->Advance();
    switch (c) {
    case ('('):
        this->AddToken(TokenType::LEFT_PAREN);
        break;
    case (')'):
        this->AddToken(TokenType::RIGHT_PAREN);
        break;
    case ('{'):
        this->AddToken(TokenType::LEFT_BRACE);
        break;
    case ('}'):
        this->AddToken(TokenType::RIGHT_BRACE);
        break;
    case ('.'):
        this->AddToken(TokenType::DOT);
        break;
    case (','):
        this->AddToken(TokenType::COMMA);
        break;
    case ('+'):
        this->AddToken(TokenType::PLUS);
        break;
    case ('-'):
        this->AddToken(TokenType::MINUS);
        break;
    case ('#'):
        this->AddToken(TokenType::HASH);
        break;
    case (':'):
        this->AddToken(TokenType::COLON);
        break;
    case (';'):
        this->AddToken(TokenType::SEMICOLON);
        break;
    case ('*'):
        this->AddToken(TokenType::STAR);
        break;
    case ('!'):
        this->AddToken(this->Match('=') ? 
            TokenType::BANG_EQUAL : TokenType::BANG);
        break;
    case ('='):
        this->AddToken(this->Match('=') ? 
            TokenType::EQUAL_EQUAL : TokenType::EQUAL);
        break;
    case ('<'):
        this->AddToken(this->Match('=') ? 
            TokenType::LESS_EQUAL : TokenType::LESS);
        break;
    case ('>'):
        this->AddToken(this->Match('=') ? 
            TokenType::GREATER_EQUAL : TokenType::GREATER);
        break;
    case ('/'):
        if (Match('/')) 
        {
            while ((this->stream.peek() != '\n' && !this->stream.eof())) 
            {
                this->Advance();
            }
        }
        else 
        {
            AddToken(TokenType::SLASH);
        }
        break;
    case (' '):
        break;
    case ('\r'):
    case ('\n'):
    case ('\t'):
        this->line++;
        this->column = 0;
        break;
    case ('"'):
        this->ScanString();
        break;
    default:
        if (isdigit(c))
        {
            this->ScanNumber(c);
        }
        else if (isalpha(c) || c == '_')
        {
            this->ScanIdentifier(c);
        }
        else 
        {
            if (this->stream.eof())
                return;
            std::stringstream ss;
            ss << "Unexpected character '" << c << "'" << std::endl;
            throw ScanException(ss.str(), this->line, this->column);
        }
    }
}
