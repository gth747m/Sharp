#include "BlockStatement.hpp"

BlockStatement::BlockStatement(std::vector<std::unique_ptr<Statement>>&& statements) :
    statements(std::move(statements))
{
}
