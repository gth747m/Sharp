#pragma once

#include <ostream>

#include "Expression.hpp"
#include "../Token.hpp"

class VariableExpression : public Expression
{
public:
    VariableExpression(Token&& name);
    virtual ~VariableExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    Token name;
};