#include "CallExpression.hpp"

CallExpression::CallExpression(std::unique_ptr<Expression>&& callee, Token&& paren, std::vector<std::unique_ptr<Expression>>&& args) :
    callee(std::move(callee)),
    paren(std::move(paren)),
    args(std::move(args))
{
}

CallExpression::~CallExpression()
{
}

void CallExpression::Print(std::ostream& os)
{
    os << "Call Expression:" << std::endl
        << "    call = {" << std::endl
        << this->callee.get()
        << "}" << std::endl
        << "    parn = " << this->paren << std::endl
        << "    args = {" << std::endl;
    for (const auto& arg : this->args) {
        os << arg.get();
    }
    os << "}" << std::endl;
}