#pragma once

#include <memory>

#include "Expression.hpp"
#include "../Token.hpp"

class UnaryExpression : public Expression
{
public:
    UnaryExpression(Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~UnaryExpression();
protected:
private:
    Token optor;
    std::unique_ptr<Expression> right;
};