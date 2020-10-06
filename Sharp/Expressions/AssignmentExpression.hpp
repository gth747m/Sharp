#pragma once

#include <memory>

#include "Expression.hpp"
#include "../Token.hpp"

class AssignmentExpression : public Expression
{
public:
    AssignmentExpression(Token&& name, std::unique_ptr<Expression>&& value);
    virtual ~AssignmentExpression();
protected:
private:
    Token name;
    std::unique_ptr<Expression> value;
};

