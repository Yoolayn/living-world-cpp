#pragma once
#include <iostream>

#define TODO1(str) std::cerr << __FILE__ << ":" << __LINE__ << ":TODO -> " << str << std::endl
#define TODO0() std::cerr << __FILE__ << ":" << __LINE__ << ":TODO" << std::endl

#define GET_MACRO(_0, NAME, ...) NAME
#define TODO(...) GET_MACRO(__VA_ARGS__ __VA_OPT__(, ) TODO1, TODO0)(__VA_ARGS__)

#ifdef DEBUG
#define LOG(...) do { std::cerr << __FILE__ << ":" << __LINE__ << ":" << __VA_ARGS__ << std::endl; } while (0)
#else
#define LOG(...) do { } while (0)
#endif
