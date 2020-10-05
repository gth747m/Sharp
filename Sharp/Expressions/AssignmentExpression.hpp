#pragma once

#include "Expression.hpp"
#include "../Token.hpp"

class AssignmentExpression : public Expression
{
public:
    AssignmentExpression(Token&& name, Expression&& value);
    virtual ~AssignmentExpression();
protected:
private:
    Token name;
    Expression value;
};

