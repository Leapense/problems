#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
#include <unordered_set>

using namespace std;

struct Fraction {
    long long num, den;
    Fraction(long long n, long long d) : num(n), den(d) {
        normalize();
    }

    Fraction() : num(0), den(1) {}

    void normalize() {
        if (den < 0) {num = -num; den = -den;}
        long long g = gcd(abs(num), abs(den));
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

Fraction add(const Fraction &a, const Fraction &b) {
    Fraction res(a.num * b.den + b.num * a.den, a.den * b.den);
    return res;
}

Fraction sub(const Fraction &a, const Fraction &b) {
    Fraction res(a.num * b.den - b.num * a.den, a.den * b.den);
    return res;
}

Fraction mul(const Fraction &a, const Fraction &b) {
    Fraction res(a.num * b.num, a.den * b.den);
    return res;
}

bool divisible(const Fraction &a, const Fraction &b) {
    return !(b.num == 0);
}

Fraction divide(const Fraction &a, const Fraction &b, bool &ok) {
    ok = true;
    if (b.num == 0) {
        ok = false;
        return Fraction(0, 1);
    }
    Fraction res(a.num * b.den, a.den * b.num);
    return res;
}

vector<char> ops = {'+', '-', '*', '/'};

vector<pair<string, Fraction>> computeAll(const vector<string>& tokens, int l, int r) {
    vector<pair<string, Fraction>> res;
    if (l == r) {
        Fraction f(stoll(tokens[l]), 1);
        res.push_back({tokens[l], f});
        return res;
    }

    for (int i = l + 1; i < r; i += 2) {
        char op = tokens[i][0];
        auto leftRes = computeAll(tokens, l, i - 1);
        auto rightRes = computeAll(tokens, i + 1, r);

        for (auto &L : leftRes) {
            for (auto &R : rightRes) {
                bool ok = true;
                Fraction val;
                if (op == '+') {
                    val = add(L.second, R.second);
                } else if (op == '-') {
                    val = sub(L.second, R.second);
                } else if (op == '*') {
                    val = mul(L.second, R.second);
                } else if (op == '/') {
                    if (R.second.num == 0) {ok = false;}
                    else {
                        val = divide(L.second, R.second, ok);
                    }
                }

                if (ok) {
                    string expr = "(" + L.first + string(1, op) + R.first + ")";
                    res.push_back({expr, val});
                }
            }
        }
    }

    return res;
}

int main()
{
    string input = "12340";
    ofstream out("results.txt");
    if (!out) {
        cerr << "Failed to open output file\n";
        return 1;
    }

    int n = input.size();

    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
        vector<string> numbers;
        string cur = "";
        cur.push_back(input[0]);

        for (int i = 0; i < n - 1; i++) {
            if (mask & (1 << i)) {
                numbers.push_back(cur);
                cur = "";
                cur.push_back(input[i + 1]);
            } else {
                cur.push_back(input[i + 1]);
            }
        }
        numbers.push_back(cur);

        int m = numbers.size();
        if (m < 2) continue;

        int opCount = m - 1;
        for (int opMask = 0; opMask < (int)pow(4, opCount); opMask++) {
            int tmp = opMask;
            vector<string> tokens;
            tokens.push_back(numbers[0]);
            for (int i = 0; i < opCount; i++) {
                int opIndex = tmp % 4;
                tmp /= 4;
                tokens.push_back(string(1, ops[opIndex]));
                tokens.push_back(numbers[i + 1]);
            }

            auto exprs = computeAll(tokens, 0, tokens.size() - 1);
            for (auto &p : exprs) {
                if (p.second.num == 100 && p.second.den == 1) {
                    string expr = p.first;
                    if (expr.front() == '(' && expr.back() == ')') {
                        string inner = expr.substr(1, expr.size() - 2);
                        if (inner.size() < expr.size()) {
                            expr = inner;
                        }
                    }
                    out << expr;
                }
                out << p.first << " " << p.second.num << "/" << p.second.den << "\n";
            }
        }
    }
    out.close();
    return 0;
}