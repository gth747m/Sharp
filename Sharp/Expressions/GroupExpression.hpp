#pragma once

#include <memory>

#include "Expression.hpp"

class GroupExpression : public Expression
{
public:
    GroupExpression(std::unique_ptr<Expression>&& expression);
    virtual ~GroupExpression();
protected:
private:
    std::unique_ptr<Expression> expression;
};