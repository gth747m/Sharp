#include "Literal.hpp"


template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

std::ostream& operator<<(std::ostream& os, Literal literal)
{
    std::visit(overload{
            [&](int& intLit) {os << intLit << std::endl; },
            [&](int64_t& intLit) {os << intLit << std::endl; },
            [&](float& floatLit) {os << floatLit << std::endl; },
            [&](double& floatLit) {os << floatLit << std::endl; },
            [&](char& charLit) {os << "'" << charLit << "'" << std::endl; },
            [&](std::string& strLit) {os << "\"" << strLit << "\"" << std::endl; }
        }, literal);
    return os;
}
