#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <algorithm>
#include <cctype>
#include <utility>

std::string toLowerStr(const std::string& s);
bool ci_less(const std::string& a, const std::string& b);

template <typename T>
bool comparePairs(const std::pair<std::string, T>& a, const std::pair<std::string, T>& b) {
    if (a.second != b.second)
        return a.second > b.second;
    return ci_less(a.first, b.first);
}

#endif
