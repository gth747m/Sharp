#pragma once

#include <vector>

#include "Statement.hpp"
#include "../Token.hpp"

class FunctionStatement : public Statement
{
public:
    FunctionStatement(Token&& name, std::vector<Token>&& params, std::vector<Statement>&& body);
    virtual ~FunctionStatement() = default;
protected:
private:
    Token name;
    std::vector<Token> params;
    std::vector<Statement> body;
};