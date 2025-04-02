#include "main.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string toString128(__int128 x) {
    if (x == 0) return "0";
    bool neg = (x < 0);
    if (neg) x = -x;
    string s;

    while (x > 0) {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }

    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

__int128 convertToInteger(const string &s) {
    bool neg = false;
    int start = 0;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }

    string num;
    for (int i = start; i < s.size(); i++) {
        if (s[i] == '.') continue;
        num.push_back(s[i]);
    }

    __int128 res = 0;
    for (char c : num) {
        res = res * 10 + (c - '0');
    }

    return neg ? -res : res;
}

string multiplyDecimal(const string &A, const string &B) {
    const __int128 scale = 1000000000000000000LL;
    __int128 a = convertToInteger(A);
    __int128 b = convertToInteger(B);
    __int128 prod = a * b;

    bool neg = (prod < 0);
    if (neg) prod = -prod;

    __int128 integerPart = prod / scale;
    __int128 fractionalPart = prod % scale;

    ostringstream oss;

    if (neg) oss << "-";
    oss << toString128(integerPart) << ".";

    string frac = toString128(fractionalPart);
    while (frac.size() < 18) {
        frac = "0" + frac;
    }

    oss << frac;

    return oss.str();
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string A, B;
        cin >> A >> B;
        cout << multiplyDecimal(A, B) << "\n";
    }

    return 0;
}
#endif
