#include "UnaryExpression.hpp"

UnaryExpression::UnaryExpression(Token&& optor, std::unique_ptr<Expression>&& right) :
    optor(std::move(optor)),
    right(std::move(right))
{
}

UnaryExpression::~UnaryExpression()
{
}

void UnaryExpression::Print(std::ostream& os)
{
    os << "Unary Expression:" << std::endl
        << "    optr = '" << this->optor << "'" << std::endl
        << "    rght = {" << std::endl
        << this->right.get()
        << "}" << std::endl;
}