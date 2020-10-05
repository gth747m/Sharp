#include "CallExpression.hpp"

CallExpression::CallExpression(Expression&& callee, Token&& paren, std::vector<Expression>&& args) :
    callee(std::move(callee)),
    paren(std::move(paren)),
    args(std::move(args))
{
}

CallExpression::~CallExpression()
{
}
