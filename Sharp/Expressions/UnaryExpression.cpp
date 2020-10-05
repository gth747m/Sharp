#include "UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Token&& optor, Expression&& right) :
    optor(std::move(optor)),
    right(std::move(right))
{
}

UnaryExpression::~UnaryExpression()
{
}
