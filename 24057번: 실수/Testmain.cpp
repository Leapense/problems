#include <gtest/gtest.h>
#include <numeric>
#include <cstdlib>

// Number 구조체는 실수를 (b + c√d) / a 형태로 나타냅니다.
struct Number {
    long long a, b, c, d;
};

// 최대공약수를 구하는 함수 (음수도 처리)
long long gcd_ll(long long x, long long y) {
    if (y == 0) return std::abs(x);
    return gcd_ll(y, x % y);
}

// a, b, c의 최대공약수를 구하는 함수
long long gcd3(long long a, long long b, long long c) {
    return gcd_ll(gcd_ll(a, b), c);
}

// 정규화: a > 0, gcd(a, b, c) = 1, 그리고 만약 c == 0이면 d는 0
void normalize(Number &num) {
    if (num.a < 0) {
        num.a = -num.a;
        num.b = -num.b;
        num.c = -num.c;
    }
    long long g = gcd3(num.a, num.b, num.c);
    if(g != 0) {
        num.a /= g;
        num.b /= g;
        num.c /= g;
    }
    if(num.c == 0) num.d = 0;
}

// 덧셈: A + B = (b1a2 + b2a1 + (c1a2 + c2a1)√d) / (a1a2)
Number add(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * B.a;
    res.b = A.b * B.a + B.b * A.a;
    res.c = A.c * B.a + B.c * A.a;
    res.d = A.d;  // 문제 조건에 따라 A와 B의 d는 동일함
    normalize(res);
    return res;
}

// 뺄셈: A - B = (b1a2 - b2a1 + (c1a2 - c2a1)√d) / (a1a2)
Number subtract(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * B.a;
    res.b = A.b * B.a - B.b * A.a;
    res.c = A.c * B.a - B.c * A.a;
    res.d = A.d;
    normalize(res);
    return res;
}

// 곱셈: A * B = (b1b2 + c1c2*d + (b1c2 + c1b2)√d) / (a1a2)
Number multiply(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * B.a;
    res.b = A.b * B.b + A.c * B.c * A.d;  // A.d == B.d
    res.c = A.b * B.c + A.c * B.b;
    res.d = A.d;
    normalize(res);
    return res;
}

// 나눗셈:
// A / B = a2*(b1 + c1√d) / (a1*(b2 + c2√d))
//       = a2*(b1 + c1√d)*(b2 - c2√d) / (a1*(b2^2 - c2^2*d))
//       = [a2*(b1b2 - c1c2*d) + a2*(b2c1 - b1c2)√d] / [a1*(b2^2 - c2^2*d)]
Number divide(const Number &A, const Number &B) {
    Number res;
    res.a = A.a * (B.b * B.b - B.c * B.c * A.d);
    res.b = B.a * (A.b * B.b - A.c * B.c * A.d);
    res.c = B.a * (B.b * A.c - A.b * B.c);
    res.d = A.d;
    normalize(res);
    return res;
}

// sample input 1을 기반으로 한 테스트 케이스 작성
TEST(ArithmeticTest, SampleTest) {
    // A: 2 3 2 5, B: 2 1 -4 5
    Number A = {2, 3, 2, 5};
    Number B = {2, 1, -4, 5};

    Number sum = add(A, B);
    Number diff = subtract(A, B);
    Number prod = multiply(A, B);
    Number quot = divide(A, B);

    // 예상 출력:
    // A+B: 1 2 -1 5
    // A-B: 1 1 3 5
    // A*B: 4 -37 -10 5
    // A/B: 79 -43 -14 5

    EXPECT_EQ(sum.a, 1);
    EXPECT_EQ(sum.b, 2);
    EXPECT_EQ(sum.c, -1);
    EXPECT_EQ(sum.d, 5);

    EXPECT_EQ(diff.a, 1);
    EXPECT_EQ(diff.b, 1);
    EXPECT_EQ(diff.c, 3);
    EXPECT_EQ(diff.d, 5);

    EXPECT_EQ(prod.a, 4);
    EXPECT_EQ(prod.b, -37);
    EXPECT_EQ(prod.c, -10);
    EXPECT_EQ(prod.d, 5);

    EXPECT_EQ(quot.a, 79);
    EXPECT_EQ(quot.b, -43);
    EXPECT_EQ(quot.c, -14);
    EXPECT_EQ(quot.d, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

