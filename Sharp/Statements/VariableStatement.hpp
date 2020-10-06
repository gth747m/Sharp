#pragma once

#include <memory>

#include "Statement.hpp"
#include "../Token.hpp"
#include "../Expressions/Expression.hpp"

class VariableStatement : public Statement
{
public:
    VariableStatement(Token&& name, std::unique_ptr<Expression>&& initializer);
    virtual ~VariableStatement() = default;
protected:
private:
    Token name;
    std::unique_ptr<Expression> initializer;
};