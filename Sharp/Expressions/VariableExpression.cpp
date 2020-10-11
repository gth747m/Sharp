#include "VariableExpression.hpp"

VariableExpression::VariableExpression(Token&& name) :
    name(std::move(name))
{
}

VariableExpression::~VariableExpression()
{
}

void VariableExpression::Print(std::ostream& os)
{
    os << "Variable Expression:" << std::endl
        << "    name = '" << this->name << "'" << std::endl;
}