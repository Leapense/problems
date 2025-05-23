#include <bits/stdc++.h>
using namespace std;

struct Fraction {
    long long num;
    long long den;
};

long long gcdLL(long long a, long long b) {
    if (b == 0) return a > 0 ? a : -a;
    return gcdLL(b, a % b);
}

Fraction addFrac(const Fraction &a, const Fraction &b) {
    Fraction res;
    long long numerator = a.num * b.den + b.num * a.den;
    long long denominator = a.den * b.den;

    long long g = gcdLL(numerator, denominator);
    numerator /= g;
    denominator /= g;

    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }

    res.num = numerator;
    res.den = denominator;
    return res;
}

Fraction subFrac(const Fraction &a, const Fraction &b) {
    Fraction res;

    long long numerator = a.num * b.den - b.num * a.den;
    long long denominator = a.den * b.den;

    long long g = gcdLL(numerator, denominator);
    numerator /= g;
    denominator /= g;

    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }

    res.num = numerator;
    res.den = denominator;
    return res;
}

Fraction parseDirection(const vector<string> &tokens, int idx) {
    if (idx == (int)tokens.size() - 1) {
        if (tokens[idx] == "north") {
            return {0,1};
        } else {
            return {90,1};
        }
    }

    Fraction subDir = parseDirection(tokens, idx + 1);

    int n = (int)tokens.size() - (idx + 1);

    Fraction shift = {90, 1LL << n};

    if (tokens[idx] == "north") {
        return subFrac(subDir, shift);
    } else {
        return addFrac(subDir, shift);
    }
}

vector<string> tokenizeDirection(const string &s) {
    vector<string> tokens;
    int pos = 0;

    while (pos < (int)s.size()) {
        if (s.compare(pos, 5, "north") == 0) {
            tokens.push_back("north");
            pos += 5;
        } else {
            tokens.push_back("west");
            pos += 4;
        }
    }

    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        string line;
        if (!getline(cin, line)) break;
        if (line == "#") break;

        vector<string> tokens = tokenizeDirection(line);
        Fraction ans = parseDirection(tokens, 0);

        if (ans.den == 1) {
            cout << ans.num << "\n";
        } else {
            cout << ans.num << "/" << ans.den << "\n";
        }
    }

    return 0;
}