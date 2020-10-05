#include "ExpressionStatement.hpp"

#include <utility>

ExpressionStatement::ExpressionStatement(Expression&& expression) :
    expression(std::move(expression))
{
}
