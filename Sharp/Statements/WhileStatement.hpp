#pragma once

#include <memory>

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class WhileStatement : public Statement
{
public:
    WhileStatement(std::unique_ptr<Expression>&& condition, std::unique_ptr<Statement>&& body);
    virtual ~WhileStatement() = default;
protected:
private:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> body;
};
