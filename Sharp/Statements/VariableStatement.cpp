#include "VariableStatement.hpp"

VariableStatement::VariableStatement(Token&& name, std::unique_ptr<Expression>&& initializer) :
    name(std::move(name)),
    initializer(std::move(initializer))
{
}
