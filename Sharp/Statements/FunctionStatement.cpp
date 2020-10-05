#include "FunctionStatement.hpp"

FunctionStatement::FunctionStatement(Token&& name, std::vector<Token>&& params, std::vector<Statement>&& body) :
    name(std::move(name)),
    params(std::move(params)),
    body(std::move(body))
{
}
