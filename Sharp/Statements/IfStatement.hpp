#pragma once

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class IfStatement : public Statement
{
public:
    IfStatement(Expression& condition, Statement&& thenBranch, Statement&& elseBranch);
    virtual ~IfStatement() = default;
protected:
private:
    Expression condition;
    Statement thenBranch;
    Statement elseBranch;
};