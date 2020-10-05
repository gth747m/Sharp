#include "VariableExpression.hpp"

VariableExpression::VariableExpression(Token&& name) :
    name(std::move(name))
{
}

VariableExpression::~VariableExpression()
{
}
