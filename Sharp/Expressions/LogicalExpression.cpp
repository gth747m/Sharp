#include "LogicalExpression.hpp"

LogicalExpression::LogicalExpression(Expression&& left, Token&& optor, Expression&& right) :
    left(std::move(left)),
    optor(std::move(optor)),
    right(std::move(right))
{
}

LogicalExpression::~LogicalExpression()
{
}