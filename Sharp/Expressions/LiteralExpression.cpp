#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(Literal&& literal) :
    literal(std::move(literal))
{
}

LiteralExpression::~LiteralExpression()
{
}
