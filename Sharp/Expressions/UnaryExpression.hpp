#pragma once

#include "Expression.hpp"
#include "../Token.hpp"

class UnaryExpression : public Expression
{
public:
    UnaryExpression(Token&& optor, Expression&& right);
    virtual ~UnaryExpression();
protected:
private:
    Token optor;
    Expression right;
};