#pragma once

#include <memory>

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class IfStatement : public Statement
{
public:
    IfStatement(std::unique_ptr<Expression>& condition, std::unique_ptr<Statement>&& thenBranch, std::unique_ptr<Statement>&& elseBranch);
    virtual ~IfStatement() = default;
protected:
private:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> thenBranch;
    std::unique_ptr<Statement> elseBranch;
};