#pragma once

#include "Expression.hpp"
#include "../Token.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(Expression&& left, Token&& optor, Expression&& right);
    virtual ~BinaryExpression();
protected:
private:
    Expression left;
    Token optor;
    Expression right;
};