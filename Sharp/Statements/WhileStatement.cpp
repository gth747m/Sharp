#include "WhileStatement.hpp"

#include <utility>

WhileStatement::WhileStatement(std::unique_ptr<Expression>&& condition, std::unique_ptr<Statement>&& body) :
    condition(std::move(condition)),
    body(std::move(body))
{
}

void WhileStatement::Print(std::ostream& os)
{
    os << "While Statement:" << std::endl
        << " cond = {" << std::endl
        << this->condition.get()
        << "}" << std::endl
        << " body = {" << std::endl
        << this-> body.get()
        << "}" << std::endl;
}