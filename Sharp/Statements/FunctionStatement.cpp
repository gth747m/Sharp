#include "FunctionStatement.hpp"

FunctionStatement::FunctionStatement(Token&& name, std::vector<Token>&& params, std::vector<std::unique_ptr<Statement>>&& body) :
    name(std::move(name)),
    params(std::move(params)),
    body(std::move(body))
{
}

void FunctionStatement::Print(std::ostream& os)
{
    os << "Function Statement:" << std::endl
        << "    name = '" << this->name << "'" << std::endl
        << "    params = {" << std::endl;
    for (auto& param : this->params)
    {
        os << "    " << param << std::endl;
    }
    os << "}" << std::endl;
}