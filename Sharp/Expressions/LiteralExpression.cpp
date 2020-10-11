#include "LiteralExpression.hpp"

LiteralExpression::LiteralExpression(Literal&& literal) :
    literal(std::move(literal))
{
}

LiteralExpression::~LiteralExpression()
{
}

void LiteralExpression::Print(std::ostream& os)
{
    os << "Literal Expression:" << std::endl
        << "    litr = " << this->literal << std::endl;
}