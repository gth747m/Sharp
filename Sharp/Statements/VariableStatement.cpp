#include "VariableStatement.hpp"

VariableStatement::VariableStatement(Token&& name, Expression&& initializer) :
    name(std::move(name)),
    initializer(std::move(initializer))
{
}
