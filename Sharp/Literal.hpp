#pragma once

#include <ostream>
#include <variant>

using Literal = std::variant<int, int64_t, float, double, char, std::string>;

std::ostream& operator<<(std::ostream& os, Literal literal);
