#include "Scanner.h"

#include <cctype>
#include <exception>
#include <map>

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
    };

Scanner::Scanner(std::istream& stream) :
    currChar(0),
    currString(),
    line(0),
    stream(stream),
    tokens(std::vector<Token>())
{
}

Scanner::~Scanner()
{
}

std::vector<Token> Scanner::ScanTokens(std::istream& stream)
{
    Scanner scanner = Scanner(stream);
    return scanner.GetTokens();
}

std::vector<Token> Scanner::GetTokens() const
{
    return this->tokens;
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
    return this->stream.get();
}

char Scanner::Peek()
{
    if (this->stream.eof()) 
        return 0;
    return this->stream.peek();
}

char Scanner::PeekAgain()
{
    if (this->stream.eof()) 
        return 0;
    char c = this->stream.get();
    if (this->stream.eof())
    {
        this->stream.putback(c);
        return 0;
    }
    char nextChar = this->stream.peek();
    this->stream.putback(c);
    return nextChar;
}

void Scanner::AddToken(TokenType&& token)
{
    this->AddToken(std::move(token), std::move(Literal()));
}

void Scanner::AddToken(TokenType&& token, Literal literal)
{
    this->tokens.push_back(Token(std::move(token), 
        this->currString.str(), literal, line));
}

void Scanner::ScanIdentifier()
{
}

void Scanner::ScanNumber()
{
}

void Scanner::ScanString()
{
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
            while ((Peek() != '\n' && !this->stream.eof())) 
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
    case ('\r'):
    case ('\n'):
    case ('\t'):
        this->line++;
        break;
    case ('"'):
        this->ScanString();
        break;
    default:
        if (isdigit(c))
        {
            this->ScanNumber();
        }
        else if (isalpha(c))
        {
            this->ScanIdentifier();
        }
        else 
        {
            std::string msg = "Unexpected character '" + c;
            throw std::runtime_error(msg + "'");
        }
    }
}
