#include "ParseException.hpp"

ParseException::ParseException(const std::string& what, const int line, const int column) :
    std::runtime_error(what),
    line(line),
    column(column)
{
}

ParseException::ParseException(const char* what, const int line, const int column) :
    std::runtime_error(what),
    line(line),
    column(column)
{
}

int ParseException::GetLine() const
{
    return this->line;
}

int ParseException::GetColumn() const
{
    return this->column;
}
