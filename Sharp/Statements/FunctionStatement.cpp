#include "FunctionStatement.hpp"

FunctionStatement::FunctionStatement(Token&& name, std::vector<Token>&& params, std::vector<std::unique_ptr<Statement>>&& body) :
    name(std::move(name)),
    params(std::move(params)),
    body(std::move(body))
{
}

void FunctionStatement::Print(std::ostream& os)
{
    os << "";
}