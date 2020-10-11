#include "BlockStatement.hpp"

BlockStatement::BlockStatement(std::vector<std::unique_ptr<Statement>>&& statements) :
    statements(std::move(statements))
{
}

void BlockStatement::Print(std::ostream& os)
{
    os << "Block Statement:" << std::endl
        << " stmt = {" << std::endl;
    for (const auto& stmt : this->statements)
    {
        os << stmt.get();
    }
    os << "}" << std::endl;
}