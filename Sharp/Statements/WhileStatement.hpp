#pragma once

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class WhileStatement : public Statement
{
public:
    WhileStatement(Expression&& condition, Statement&& body);
    virtual ~WhileStatement() = default;
protected:
private:
    Expression condition;
    Statement body;
};
