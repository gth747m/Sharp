#pragma once

#include <memory>
#include <ostream>

#include "Expression.hpp"
#include "../Token.hpp"

class UnaryExpression : public Expression
{
public:
    UnaryExpression(Token&& optor, std::unique_ptr<Expression>&& right);
    virtual ~UnaryExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    Token optor;
    std::unique_ptr<Expression> right;
};