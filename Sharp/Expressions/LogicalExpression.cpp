#include "LogicalExpression.hpp"

LogicalExpression::LogicalExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right) :
    left(std::move(left)),
    optor(std::move(optor)),
    right(std::move(right))
{
}

LogicalExpression::~LogicalExpression()
{
}