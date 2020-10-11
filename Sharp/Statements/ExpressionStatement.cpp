#include "ExpressionStatement.hpp"

#include <memory>
#include <utility>

ExpressionStatement::ExpressionStatement(std::unique_ptr<Expression>&& expression) :
    expression(std::move(expression))
{
}

void ExpressionStatement::Print(std::ostream& os)
{
    os << "Expression Statement:" << std::endl
        << "    expr = {" << std::endl
        << this->expression.get()
        << "}" << std::endl;
}