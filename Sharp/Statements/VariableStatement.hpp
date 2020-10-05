#pragma once

#include "Statement.hpp"
#include "../Token.hpp"
#include "../Expressions/Expression.hpp"

class VariableStatement : public Statement
{
public:
    VariableStatement(Token&& name, Expression&& initializer);
    virtual ~VariableStatement() = default;
protected:
private:
    Token name;
    Expression initializer;
};