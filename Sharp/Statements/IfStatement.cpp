#include "IfStatement.hpp"

#include <utility>

IfStatement::IfStatement(std::unique_ptr<Expression>& condition, std::unique_ptr<Statement>&& thenBranch, std::unique_ptr<Statement>&& elseBranch) :
    condition(std::move(condition)),
    thenBranch(std::move(thenBranch)),
    elseBranch(std::move(elseBranch))
{
}

void IfStatement::Print(std::ostream& os)
{
    os << "";
}