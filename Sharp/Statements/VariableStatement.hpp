#pragma once

#include <memory>
#include <ostream>

#include "Statement.hpp"
#include "../Token.hpp"
#include "../Expressions/Expression.hpp"

class VariableStatement : public Statement
{
public:
    VariableStatement(Token type, Token name, std::unique_ptr<Expression>&& initializer);
    virtual ~VariableStatement() = default;
    friend std::ostream& operator<<(std::ostream& os, VariableStatement& stmt);
protected:
    virtual void Print(std::ostream& os);
private:
    Token type;
    Token name;
    std::unique_ptr<Expression> initializer;
};