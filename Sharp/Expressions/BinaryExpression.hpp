#pragma once

#include <memory>

#include "Expression.hpp"
#include "../Token.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~BinaryExpression();
protected:
private:
    std::unique_ptr<Expression> left;
    Token optor;
    std::unique_ptr<Expression> right;
};