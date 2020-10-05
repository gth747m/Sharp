#pragma once

#include <vector>

#include "Expression.hpp"
#include "../Token.hpp"

class CallExpression : public Expression
{
public:
    CallExpression(Expression&& callee, Token&& paren, std::vector<Expression>&& args);
    virtual ~CallExpression();
protected:
private:
    Expression callee;
    Token paren;
    std::vector<Expression> args;
};
