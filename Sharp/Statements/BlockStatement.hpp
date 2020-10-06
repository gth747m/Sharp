#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"

class BlockStatement : public Statement
{
public:
    BlockStatement(std::vector<std::unique_ptr<Statement>>&& statements);
    virtual ~BlockStatement() = default;
protected:
private:
    std::vector<std::unique_ptr<Statement>> statements;
};