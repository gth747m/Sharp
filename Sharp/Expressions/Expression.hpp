#pragma once

#include <ostream>

class Expression {
public:
    Expression() = default;
    virtual ~Expression() = default;
    friend std::ostream& operator<<(std::ostream& os, Expression& expr);
protected:
    virtual void Print(std::ostream& os) = 0;
private:
};

inline std::ostream& operator<<(
    std::ostream& os, 
    Expression& expr) 
{
    expr.Print(os);
    return os;
}