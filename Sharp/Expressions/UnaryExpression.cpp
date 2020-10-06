#include "UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Token&& optor, std::unique_ptr<Expression>&& right) :
    optor(std::move(optor)),
    right(std::move(right))
{
}

UnaryExpression::~UnaryExpression()
{
}
