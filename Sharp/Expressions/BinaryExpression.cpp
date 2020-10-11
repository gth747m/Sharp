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

void BinaryExpression::Print(std::ostream& os)
{
    os << "Binary Expression:" << std::endl
        << "    left = {" << std::endl
        << this->left.get()
        << "}" << std::endl
        << "    optr = " << this->optor << std::endl
        << "    rght = {" << std::endl
        << this->right.get()
        << "}" << std::endl;
}