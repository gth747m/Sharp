#pragma once

#include <vector>

#include "Statement.hpp"

class BlockStatement : public Statement
{
public:
    BlockStatement(std::vector<Statement>&& statements);
    virtual ~BlockStatement() = default;
protected:
private:
    std::vector<Statement> statements;
};