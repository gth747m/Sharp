#include "AssignmentExpression.hpp"

AssignmentExpression::AssignmentExpression(Token&& name, std::unique_ptr<Expression>&& value) :
    name(std::move(name)),
    value(std::move(value))
{
}

AssignmentExpression::~AssignmentExpression()
{
}

void AssignmentExpression::Print(std::ostream& os)
{
    os << "Assignment Expression:" << std::endl
        << "    name = " << this->name << std::endl
        << "    valu = {" << std::endl
        << this->value.get()
        << "}" << std::endl;
}