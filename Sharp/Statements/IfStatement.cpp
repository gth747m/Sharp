#include "IfStatement.hpp"

#include <utility>

IfStatement::IfStatement(Expression& condition, Statement&& thenBranch, Statement&& elseBranch) :
    condition(std::move(condition)),
    thenBranch(std::move(thenBranch)),
    elseBranch(std::move(elseBranch))
{
}
