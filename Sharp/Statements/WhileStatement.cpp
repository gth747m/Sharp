#include "WhileStatement.hpp"

#include <utility>

WhileStatement::WhileStatement(Expression&& condition, Statement&& body) :
    condition(std::move(condition)),
    body(std::move(body))
{
}
