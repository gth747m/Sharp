#pragma once

#include <ostream>

#include "Expression.hpp"
#include "../Literal.hpp"
#include "../Token.hpp"

class LiteralExpression : public Expression
{
public:
    LiteralExpression(Literal&& literal);
    virtual ~LiteralExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    Literal literal;
};