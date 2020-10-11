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

void LogicalExpression::Print(std::ostream& os)
{
    os << "Literal Expression:" << std::endl
        << "    left = {" << std::endl
        << this->left.get()
        << "}" << std::endl
        << "    optr = " << this->optor <<std::endl
        << "    rght = {" << std::endl
        << this->right.get()
        << "}" << std::endl;
}