#pragma once

#include "Expression.hpp"
#include "../Token.hpp"

class LogicalExpression : public Expression
{
public:
    LogicalExpression(Expression&& left, Token&& optor, Expression&& right);
    virtual ~LogicalExpression();
protected:
private:
    Expression left;
    Token optor;
    Expression right;
};
