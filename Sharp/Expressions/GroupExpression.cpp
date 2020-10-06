#include "GroupExpression.hpp"

#include <utility>

GroupExpression::GroupExpression(std::unique_ptr<Expression>&& expression) :
    expression(std::move(expression))
{
}

GroupExpression::~GroupExpression()
{
}
