#pragma once

#include <stdexcept>

class ScanException : public virtual std::runtime_error
{
public:
    ScanException(const std::string& what, const int line, const int column);
    ScanException(const char* what, const int line, const int column);
    int GetLine() const;
    int GetColumn() const;
private:
    const int line;
    const int column;
};