#include "Parser.hpp"

#include <sstream>

#include "ParseException.hpp"
#include "Statements/BlockStatement.hpp"
#include "Statements/ExpressionStatement.hpp"
#include "Statements/FunctionStatement.hpp"
#include "Statements/IfStatement.hpp"
#include "Statements/VariableStatement.hpp"
#include "Statements/WhileStatement.hpp"

Parser::Parser(std::vector<Token>&& tokens) :
    tokens(std::move(tokens))
{
    this->current = this->tokens.begin();
}

std::vector<std::unique_ptr<Statement>> Parser::Parse()
{
    std::vector<std::unique_ptr<Statement>> statements;
    while (this->current != this->tokens.end())
    {
        statements.emplace_back(std::move(this->ParseDeclaration()));
    }
    return statements;
}

Token Parser::Consume(TokenType type)
{
    if ((this->current >= this->tokens.end()) || 
        (this->current->GetType() != type))
    {
        std::stringstream msg;
        msg << "Expected a '" << type << "' but found '"
            << this->current->GetLiteral() << "'." << std::endl;
        throw new ParseException(msg.str(), this->current->GetLine(),
            this->current->GetColumn());
    }
    return *this->current++;
}

std::unique_ptr<Expression> Parser::ParseAddition()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseAssignment()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseCall()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseComparison()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseEquality()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseExpression()
{
    return std::move(this->ParseAssignment());
}

std::unique_ptr<Expression> Parser::ParseMultiplication()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseOr()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParsePrimary()
{
    throw new std::exception();
}

std::unique_ptr<Expression> Parser::ParseUnary()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseBlock()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseDeclaration()
{
    switch (this->current->GetType())
    {
    case (TokenType::INT):
    case (TokenType::UINT):
    case (TokenType::LONG):
    case (TokenType::ULONG):
    case (TokenType::FLOAT):
    case (TokenType::DOUBLE):
    case (TokenType::VAR):
        return std::move(this->ParseVariable());
        break;
    case (TokenType::FUNCTION):
        return std::move(this->ParseFunction());
    default:
        return std::move(this->ParseStatement());
    }
}

std::unique_ptr<Statement> Parser::ParseExpressionStatement()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseFor()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseFunction()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseIf()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseStatement()
{
    switch (this->current->GetType())
    {
    case (TokenType::FOR):
        return std::move(this->ParseFor());
        break;
    case (TokenType::IF):
        return std::move(this->ParseIf());
        break;
    case (TokenType::LEFT_BRACE):
        return std::move(this->ParseBlock());
        break;
    case (TokenType::WHILE):
        return std::move(this->ParseWhile());
        break;
    default:
        return std::move(this->ParseExpressionStatement());
    }
}

std::unique_ptr<Statement> Parser::ParseWhile()
{
    throw new std::exception();
}

std::unique_ptr<Statement> Parser::ParseVariable()
{
    Token type = this->Consume(TokenType::VARIABLE_TYPE);
    Token name = this->Consume(TokenType::IDENTIFIER);
    this->Consume(TokenType::EQUAL);
    std::unique_ptr<Expression> init = this->ParseExpression();
    this->Consume(TokenType::SEMICOLON);
    return std::make_unique<VariableStatement>(type, name, std::move(init));
}
