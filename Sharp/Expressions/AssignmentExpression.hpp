#pragma once

#include <memory>
#include <ostream>

#include "Expression.hpp"
#include "../Token.hpp"

class AssignmentExpression : public Expression
{
public:
    AssignmentExpression(Token&& name, std::unique_ptr<Expression>&& value);
    virtual ~AssignmentExpression();
protected:
    virtual void Print(std::ostream& os) = 0;
private:
    Token name;
    std::unique_ptr<Expression> value;
};

