#include "VariableStatement.hpp"

VariableStatement::VariableStatement(Token type, Token name, std::unique_ptr<Expression>&& initializer) :
    type(std::move(type)),
    name(std::move(name)),
    initializer(std::move(initializer))
{
}

void VariableStatement::Print(std::ostream& os)
{
    os << "Variable Declaration:" << std::endl
        << "    type = '" << this->type << "'" << std::endl
        << "    name = '" << this->name << "'" << std::endl
        << "    init = {" << std::endl
        << this->initializer.get()
        << "}" << std::endl;
}
