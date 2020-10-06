#pragma once

#include <memory>

#include "Statement.hpp"
#include "../Expressions/Expression.hpp"

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(std::unique_ptr<Expression>&& expression);
    virtual ~ExpressionStatement() = default;
protected:
private:
    std::unique_ptr<Expression> expression;
};