#pragma once

#include <memory>
#include <ostream>
#include <vector>

#include "Expression.hpp"
#include "../Token.hpp"

class CallExpression : public Expression
{
public:
    CallExpression(std::unique_ptr<Expression>&& callee, Token&& paren, std::vector<std::unique_ptr<Expression>>&& args);
    virtual ~CallExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    std::unique_ptr<Expression> callee;
    Token paren;
    std::vector<std::unique_ptr<Expression>> args;
};
