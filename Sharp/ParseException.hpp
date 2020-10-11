#pragma once

#include <stdexcept>

class ParseException : public virtual std::runtime_error
{
public:
    ParseException(const std::string& what, const int line, const int column);
    ParseException(const char* what, const int line, const int column);
    int GetLine() const;
    int GetColumn() const;
private:
    const int line;
    const int column;
};