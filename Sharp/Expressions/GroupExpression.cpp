#include "GroupExpression.hpp"

#include <utility>

GroupExpression::GroupExpression(Expression&& expression) :
    expression(std::move(expression))
{
}

GroupExpression::~GroupExpression()
{
}
