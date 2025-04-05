#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <cstdlib>

bool isValidNumber(const std::string &s) {
    int n = s.size();
    if (n == 0) return false;

    int start = 0;
    if (s[0] == '-') {
        if (n == 1) return false;
        start = 1;
    }

    if (s[start] == '0' && n - start > 1) return false;
    return true;
}

long long toLL(const std::string &s) {
    return stoll(s);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string equation;
    std::cin >> equation;

    std::set<char> usedDigits;
    for (char c : equation) {
        if (isdigit(c)) {
            usedDigits.insert(c);
        }
    }

    int ans = -1;
    for (int cand = 0; cand <= 9; cand++) {
        char candidate = '0' + cand;
        if (usedDigits.find(candidate) != usedDigits.end()) continue;

        std::string replaced;
        for (char c : equation) {
            if (c == '?') replaced.push_back(candidate);
            else replaced.push_back(c);
        }
        size_t startPos = (replaced[0] == '-' ? 1 : 0);
        size_t posOp = replaced.find_first_of("+-*", startPos);
        if (posOp == std::string::npos) continue;
        char op = replaced[posOp];

        std::string left = replaced.substr(0, posOp);
        size_t posEqual = replaced.find('=', posOp);
        std::string middle = replaced.substr(posOp + 1, posEqual - posOp - 1);
        std::string right = replaced.substr(posEqual + 1);

        if (!isValidNumber(left) || !isValidNumber(middle) || !isValidNumber(right)) continue;

        long long num1, num2, num3;

        try {
            num1 = toLL(left);
            num2 = toLL(middle);
            num3 = toLL(right);
        } catch (...) {
            continue;
        }

        long long res = 0;
        if (op == '+') res = num1 + num2;
        else if (op == '-') res = num1 - num2;
        else if (op == '*') res = num1 * num2;
        else continue;

        if (res == num3) {
            ans = cand;
            break;
        }
    }

    if (ans == -1) std::cout << "mistake";
    else std::cout << ans;

    return 0;
}
