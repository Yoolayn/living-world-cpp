#pragma once

#define TODO1(str) std::cout << "TODO: " << str << std::endl
#define TODO0() std::cout << "TODO" << std::endl

#define GET_MACRO(_0, NAME, ...) NAME
#define TODO(...) GET_MACRO(__VA_ARGS__ __VA_OPT__(,) TODO1, TODO0)(__VA_ARGS__)
