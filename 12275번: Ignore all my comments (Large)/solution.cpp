#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ostringstream oss;
    oss << std::cin.rdbuf();
    std::string in = oss.str();

    std::string result;
    result.reserve(in.size() + 16);
    result += "Case #1:\n";

    int depth = 0;
    for (size_t i = 0; i < in.size(); ) {
        if (i + 1 < in.size() && in[i] == '/' && in[i+1] == '*') {
            ++depth;
            i += 2;
        } else if (i + 1 < in.size() && in[i] == '*' && in[i+1] == '/' && depth > 0) {
            --depth;
            i += 2;
        } else {
            if (depth == 0) {
                result += in[i];
            }
            ++i;
        }
    }

    std::cout << result;
    return 0;
}
