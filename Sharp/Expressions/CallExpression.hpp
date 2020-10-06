#pragma once

#include <memory>
#include <vector>

#include "Expression.hpp"
#include "../Token.hpp"

class CallExpression : public Expression
{
public:
    CallExpression(std::unique_ptr<Expression>&& callee, Token&& paren, std::vector<std::unique_ptr<Expression>>&& args);
    virtual ~CallExpression();
protected:
private:
    std::unique_ptr<Expression> callee;
    Token paren;
    std::vector<std::unique_ptr<Expression>> args;
};
