#pragma once

#include <memory>
#include <ostream>

#include "Expression.hpp"
#include "../Token.hpp"

class LogicalExpression : public Expression
{
public:
    LogicalExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~LogicalExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    std::unique_ptr<Expression> left;
    Token optor;
    std::unique_ptr<Expression> right;
};
