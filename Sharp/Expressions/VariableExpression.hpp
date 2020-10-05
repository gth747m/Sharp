#pragma once

#include "Expression.hpp"
#include "../Token.hpp"

class VariableExpression : public Expression
{
public:
    VariableExpression(Token&& name);
    virtual ~VariableExpression();
protected:
private:
    Token name;
};