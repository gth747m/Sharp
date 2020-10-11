#pragma once

#include <memory>
#include <ostream>

#include "Expression.hpp"

class GroupExpression : public Expression
{
public:
    GroupExpression(std::unique_ptr<Expression>&& expression);
    virtual ~GroupExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    std::unique_ptr<Expression> expression;
};