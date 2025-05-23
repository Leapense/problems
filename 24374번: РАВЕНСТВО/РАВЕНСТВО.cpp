#include <bits/stdc++.h>
using namespace std;

int findMinimumBase(const string& str) {
    char maxChar = '0';
    for (char c : str) {
        if (isalnum(c)) {
            maxChar = max(maxChar, c);
        }
    }

    if (isdigit(maxChar)) {
        return maxChar - '0' + 1;
    } else {
        return maxChar - 'A' + 11;
    }
}

long long convertToDecimal(const string& str, int base) {
    long long value = 0;

    for (char c : str) {
        value *= base;
        if (isdigit(c)) {
            value += c - '0';
        } else {
            value += c - 'A' + 10;
        }
    }

    return value;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    string expressions;
    cin >> expressions;

    int plusPos = expressions.find('+');
    int equalsPos = expressions.find('=');

    string X = expressions.substr(0, plusPos);
    string Y = expressions.substr(plusPos + 1, equalsPos - plusPos - 1);
    string Z = expressions.substr(equalsPos + 1);

    int minBase = max({findMinimumBase(X), findMinimumBase(Y), findMinimumBase(Z)});

    for (int base = minBase; base <= 36; base++) {
        long long x = convertToDecimal(X, base);
        long long y = convertToDecimal(Y, base);
        long long z = convertToDecimal(Z, base);

        if (x + y == z) {
            cout << base << endl;
            return 0;
        }
    }

    cout << "0" << endl;
    return 0;
}