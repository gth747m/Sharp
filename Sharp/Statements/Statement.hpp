#pragma once

#include <ostream>

class Statement
{
public:
    Statement() = default;
    virtual ~Statement() = default;
    friend std::ostream& operator<<(std::ostream& os, Statement& stmt);
protected:
    virtual void Print(std::ostream& os) = 0;
private:
};

inline std::ostream& operator<<(
    std::ostream& os, 
    Statement& stmt) 
{
    stmt.Print(os);
    return os;
}