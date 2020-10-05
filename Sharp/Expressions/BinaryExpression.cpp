#include "BinaryExpression.hpp"

BinaryExpression::BinaryExpression(Expression&& left, Token&& optor, Expression&& right) :
    left(std::move(left)),
    optor(std::move(optor)),
    right(std::move(right))
{
}

BinaryExpression::~BinaryExpression()
{
}
