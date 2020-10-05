#pragma once

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression&& expression);
    virtual ~ExpressionStatement() = default;
protected:
private:
    Expression expression;
};