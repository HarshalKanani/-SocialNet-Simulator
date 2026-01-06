#include "utils.hpp"

std::string toLowerStr(const std::string& s) {
    std::string t = s;
    for (char &c : t) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return t;
}

bool ci_less(const std::string& a, const std::string& b) {
    return toLowerStr(a) < toLowerStr(b);
}
