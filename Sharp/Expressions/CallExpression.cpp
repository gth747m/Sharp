#include "CallExpression.hpp"

CallExpression::CallExpression(std::unique_ptr<Expression>&& callee, Token&& paren, std::vector<std::unique_ptr<Expression>>&& args) :
    callee(std::move(callee)),
    paren(std::move(paren)),
    args(std::move(args))
{
}

CallExpression::~CallExpression()
{
}
