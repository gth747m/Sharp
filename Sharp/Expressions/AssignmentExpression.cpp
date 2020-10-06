#include "AssignmentExpression.hpp"

AssignmentExpression::AssignmentExpression(Token&& name, std::unique_ptr<Expression>&& value) :
    name(std::move(name)),
    value(std::move(value))
{
}

AssignmentExpression::~AssignmentExpression()
{
}
