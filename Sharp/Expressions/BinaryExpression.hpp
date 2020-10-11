#pragma once

#include <memory>
#include <ostream>

#include "Expression.hpp"
#include "../Token.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::unique_ptr<Expression>&& left, Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~BinaryExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    std::unique_ptr<Expression> left;
    Token optor;
    std::unique_ptr<Expression> right;
};