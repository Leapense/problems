#include <iostream>
#include <numeric>
#include <cstdlib>
using namespace std;

struct Number {
    long long a, b, c, d;
};

long long gcd_ll(long long x, long long y) {
    if (y == 0) return abs(x);
    return gcd_ll(y, x % y);
}

long long gcd3(long long a, long long b, long long c) {
    return gcd_ll(gcd_ll(a, b), c);
}

void normalize(Number &num) {
    if (num.a < 0) {
        num.a = -num.a;
        num.b = -num.b;
        num.c = -num.c;
    }

    long long g = gcd3(num.a, num.b, num.c);

    if (g != 0) {
        num.a /= g;
        num.b /= g;
        num.c /= g;
    }
    
    if (num.c == 0) num.d = 0;
}

Number add(const Number &A, const Number &B) {
    Number res;

    res.a = A.a * B.a;
    res.b = A.b * B.a + B.b * A.a;
    res.c = A.c * B.a + B.c * A.a;
    res.d = A.d;
    normalize(res);
    return res;
}

Number subtract(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * B.a;
    res.b = A.b * B.a - B.b * A.a;
    res.c = A.c * B.a - B.c * A.a;
    res.d = A.d;
    normalize(res);
    return res;
}

Number multiply(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * B.a;
    res.b = A.b * B.b + A.c * B.c * A.d;
    res.c = A.b * B.c + A.c * B.b;
    res.d = A.d;
    normalize(res);
    return res;
}

Number divide(const Number &A, const Number &B) {
    Number res;
    long long numerator_common = A.b * B.b - A.c * B.c * A.d;
    long long numerator_sqrt = B.b * A.c - A.b * B.c;
    long long denominator = B.b * B.b - B.c * B.c * A.d;

    res.a = A.a * denominator;
    res.b = B.a * numerator_common;
    res.c = B.a * numerator_sqrt;
    res.d = A.d;
    normalize(res);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Number A, B;
    cin >> A.a >> A.b >> A.c >> A.d;
    cin >> B.a >> B.b >> B.c >> B.d;

    Number sum = add(A, B);
    Number diff = subtract(A, B);
    Number prod = multiply(A, B);
    Number quot = divide(A, B);

    cout << sum.a << ' ' << sum.b << ' ' << sum.c << ' ' << sum.d << '\n';
    cout << diff.a << ' ' << diff.b << ' ' << diff.c << ' ' << diff.d << '\n';
    cout << prod.a << ' ' << prod.b << ' ' << prod.c << ' ' << prod.d << '\n';
    cout << quot.a << ' ' << quot.b << ' ' << quot.c << ' ' << quot.d << '\n';
    return 0;
}
