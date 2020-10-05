#pragma once

#include "Expression.hpp"

class GroupExpression : public Expression
{
public:
    GroupExpression(Expression&& expression);
    virtual ~GroupExpression();
protected:
private:
    Expression expression;
};