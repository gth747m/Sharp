#include "Parser.hpp"

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

std::unique_ptr<Statement> Parser::ParseDeclaration()
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

std::unique_ptr<Statement> Parser::ParseStatement()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
}

std::unique_ptr<Statement> Parser::ParseFor()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
    //return std::move(std::make_unique<WhileStatement>());
}

std::unique_ptr<Statement> Parser::ParseIf()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
    //return std::move(std::make_unique<IfStatement>());
}

std::unique_ptr<Statement> Parser::ParseWhile()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
    //return std::move(std::make_unique<WhileStatement>());
}

std::unique_ptr<Statement> Parser::ParseBlock()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
    //return std::move(std::make_unique<BlockStatement>());
}

std::unique_ptr<Statement> Parser::ParseExpressionStatement()
{
    this->current++;
    return std::move(std::make_unique<Statement>());
    //return std::move(std::make_unique<ExpressionStatement>());
}
