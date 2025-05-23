#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
    Fraction(int n, int d) : numerator(n), denominator(d) {}
};

bool compare(const Fraction &a, const Fraction &b) {
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    vector<Fraction> fractions;

    for (int den = 1; den <= n; ++den) {
        for (int num = 1; num < den; ++num) {
            if (gcd(num, den) == 1) {
                if (num * p > den && num * q < den) {
                    fractions.push_back(Fraction(num, den));
                }
            }
        }
    }

    sort(fractions.begin(), fractions.end(), compare);

    for (const auto &f : fractions) {
        cout << f.numerator << "/" << f.denominator << "\n";
    }

    return 0;
}