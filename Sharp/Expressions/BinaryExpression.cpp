#include "BinaryExpression.hpp"

BinaryExpression::BinaryExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right) :
    left(std::move(left)),
    optor(std::move(optor)),
    right(std::move(right))
{
}

BinaryExpression::~BinaryExpression()
{
}
