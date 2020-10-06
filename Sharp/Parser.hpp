#pragma once

#include <memory>
#include <vector>

#include "Token.hpp"
#include "Statements/Statement.hpp"

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
    std::unique_ptr<Statement> ParseDeclaration();
    std::unique_ptr<Statement> ParseStatement();
    std::unique_ptr<Statement> ParseFor();
    std::unique_ptr<Statement> ParseIf();
    std::unique_ptr<Statement> ParseWhile();
    std::unique_ptr<Statement> ParseBlock();
    std::unique_ptr<Statement> ParseExpressionStatement();
};
