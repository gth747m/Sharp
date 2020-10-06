#include "WhileStatement.hpp"

#include <utility>

WhileStatement::WhileStatement(std::unique_ptr<Expression>&& condition, std::unique_ptr<Statement>&& body) :
    condition(std::move(condition)),
    body(std::move(body))
{
}
