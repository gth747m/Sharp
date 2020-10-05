#include "AssignmentExpression.hpp"

AssignmentExpression::AssignmentExpression(Token&& name, Expression&& value) :
    name(std::move(name)),
    value(std::move(value))
{
}

AssignmentExpression::~AssignmentExpression()
{
}
