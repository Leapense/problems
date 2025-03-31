#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::pair<std::string, int> divideBy3(const std::string& num) {
    std::string quotient;
    int remainder = 0;

    for (char ch : num) {
        int cur = remainder * 10 + (ch - '0');
        quotient.push_back((cur / 3) + '0');
        remainder = cur % 3;
    }

    size_t pos = quotient.find_first_not_of('0');
    if (pos != std::string::npos) quotient = quotient.substr(pos);
    else quotient = "0";

    return {quotient, remainder};
}

std::string addOne(std::string num) {
    int carry = 1;
    for (int i = num.size() - 1; i >= 0 && carry; i--) {
        int sum = (num[i] - '0') + carry;
        num[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) num.insert(num.begin(), '1');
    return num;
}

std::string multiplyBy3(const std::string& num) {
    int carry = 0;
    std::string result;
    result.resize(num.size());

    for (int i = num.size() - 1; i >= 0; i--) {
        int prod = (num[i] - '0') * 3 + carry;
        result[i] = (prod % 10) + '0';
        carry = prod / 10;
    }

    while (carry) {
        char digit = (carry % 10) + '0';
        result.insert(result.begin(), digit);
        carry /= 10;
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string m;
    std::cin >> m;

    std::vector<int> digits;

    std::string current = m;
    while (current != "0") {
        auto [quotient, rem] = divideBy3(current);
        int digit = rem;
        if (digit == 2) {
            digit = -1;
            quotient = addOne(quotient);
        }
        digits.push_back(digit);
        current = quotient;
    }


    std::vector<std::string> power;
    power.push_back("1");

    for (size_t i = 1; i < digits.size(); i++) {
        power.push_back(multiplyBy3(power.back()));
    }

    std::vector<std::string> left, right;

    for (size_t i = 0; i < digits.size(); i++) {
        if (digits[i] == 1) right.push_back(power[i]);
        else if(digits[i] == -1) left.push_back(power[i]);
    }

    std::sort(left.begin(), left.end(), [](const std::string &a, const std::string &b) {
        return (a.size() == b.size() ? a < b : a.size() < b.size());
    });

    std::sort(right.begin(), right.end(), [](const std::string &a, const std::string &b) {
        return (a.size() == b.size() ? a < b : a.size() < b.size());
    });

    std::cout << left.size();
    for (auto &s : left) std::cout << " " << s;
    std::cout << "\n";

    std::cout << right.size();
    for (auto &s : right) std::cout << " " << s;
    std::cout << "\n";

    return 0;
}
