#include "ExpressionStatement.hpp"

#include <memory>
#include <utility>

ExpressionStatement::ExpressionStatement(std::unique_ptr<Expression>&& expression) :
    expression(std::move(expression))
{
}
