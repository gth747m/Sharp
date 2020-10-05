#pragma once

#include "Expression.hpp"
#include "../Literal.hpp"
#include "../Token.hpp"

class LiteralExpression : public Expression
{
public:
    LiteralExpression(Literal&& literal);
    virtual ~LiteralExpression();
protected:
private:
    Literal literal;
};