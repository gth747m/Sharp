#include "GroupExpression.hpp"

#include <utility>

GroupExpression::GroupExpression(std::unique_ptr<Expression>&& expression) :
    expression(std::move(expression))
{
}

GroupExpression::~GroupExpression()
{
}

void GroupExpression::Print(std::ostream& os)
{
    os << "Group Expression:" << std::endl
        << "    expr = {" << std::endl
        << this->expression.get()
        << "}" << std::endl;
}