#pragma once

#include <memory>
#include <vector>

#include "Token.hpp"
#include "Statements/Statement.hpp"
#include "Expressions/Expression.hpp"

class Parser
{
public:
    Parser(std::vector<Token>&& tokens);
    virtual ~Parser() = default;
    std::vector<std::unique_ptr<Statement>> Parse();
private:
    // Member variables
    std::vector<Token> tokens;
    std::vector<Token>::const_iterator current;
    // Member methods
    Token Consume(TokenType type);
    // Expression
    std::unique_ptr<Expression> ParseAddition();
    std::unique_ptr<Expression> ParseAssignment();
    std::unique_ptr<Expression> ParseCall();
    std::unique_ptr<Expression> ParseComparison();
    std::unique_ptr<Expression> ParseEquality();
    std::unique_ptr<Expression> ParseExpression();
    std::unique_ptr<Expression> ParseMultiplication();
    std::unique_ptr<Expression> ParseOr();
    std::unique_ptr<Expression> ParsePrimary();
    std::unique_ptr<Expression> ParseUnary();
    // Statements
    std::unique_ptr<Statement> ParseBlock();
    std::unique_ptr<Statement> ParseDeclaration();
    std::unique_ptr<Statement> ParseExpressionStatement();
    std::unique_ptr<Statement> ParseFor();
    std::unique_ptr<Statement> ParseFunction();
    std::unique_ptr<Statement> ParseIf();
    std::unique_ptr<Statement> ParseStatement();
    std::unique_ptr<Statement> ParseWhile();
    std::unique_ptr<Statement> ParseVariable();
};
