#pragma once

#include <memory>

#include "Expression.hpp"
#include "../Token.hpp"

class LogicalExpression : public Expression
{
public:
    LogicalExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~LogicalExpression();
protected:
private:
    std::unique_ptr<Expression> left;
    Token optor;
    std::unique_ptr<Expression> right;
};
