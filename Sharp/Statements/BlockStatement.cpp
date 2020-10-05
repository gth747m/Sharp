#include "BlockStatement.hpp"

BlockStatement::BlockStatement(std::vector<Statement>&& statements) :
    statements(std::move(statements))
{
}
