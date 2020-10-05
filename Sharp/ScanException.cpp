#include "ScanException.hpp"

ScanException::ScanException(const std::string& what, const int line, const int column) :
    std::runtime_error(what),
    line(line),
    column(column)
{
}

ScanException::ScanException(const char* what, const int line, const int column) :
    std::runtime_error(what),
    line(line),
    column(column)
{
}

int ScanException::GetLine() const
{
    return this->line;
}

int ScanException::GetColumn() const
{
    return this->column;
}
