#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"
#include "../Token.hpp"

class FunctionStatement : public Statement
{
public:
    FunctionStatement(Token&& name, std::vector<Token>&& params, std::vector<std::unique_ptr<Statement>>&& body);
    virtual ~FunctionStatement() = default;
protected:
    virtual void Print(std::ostream& os);
private:
    Token name;
    std::vector<Token> params;
    std::vector<std::unique_ptr<Statement>> body;
};