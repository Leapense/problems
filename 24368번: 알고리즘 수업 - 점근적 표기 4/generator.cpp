#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to print a test case
void print_test(long long a2, long long a1, long long a0, long long c, long long n0) {
    cout << a2 << " " << a1 << " " << a0 << endl;
    cout << c << endl;
    cout << n0 << endl;
}

int main(int argc, char* argv[]) {
    // Initialize testlib generator
    registerGen(argc, argv, 1);

    // --- Manual/Edge Cases ---

    // Test 1: Simple YES case. c > a2, and condition holds from the start.
    // f(n) = 7n^2 + n + 1, c = 8, n0 = 1.
    // h(n) = n^2 - n - 1. h(1) = -1 < 0. So this should be 0. Let's fix.
    // f(n) = 7n^2 + n + 1, c=8, n0=2. h(2) = 4-2-1 = 1 > 0. h'(2) = 2*1*2-1 = 3>0. YES.
    startTest(1);
    print_test(7, 1, 1, 8, 2);

    // Test 2: Simple NO case. c < a2. Parabola opens down.
    startTest(2);
    print_test(8, 1, 1, 7, 1);
    
    // Test 3: c == a2, a1 > 0 -> NO. Line slopes down.
    startTest(3);
    print_test(5, 1, 10, 5, 1);

    // Test 4: c == a2, a1 == 0, a0 > 0 -> NO. Constant positive offset.
    startTest(4);
    print_test(5, 0, 1, 5, 10);

    // Test 5: c == a2, a1 == 0, a0 <= 0 -> YES.
    startTest(5);
    print_test(5, 0, -2, 5, 10);
    
    // Test 6: c == a2, a1 < 0, but fails at n0 -> NO.
    // h(n) = -a1*n - a0 >= 0. Let a1=-10. h(n) = 10n - a0.
    // Let a0 = 101, n0=10. h(10) = 100-101 = -1 < 0.
    startTest(6);
    print_test(3, -10, 101, 3, 10);

    // Test 7: c == a2, a1 < 0, holds at n0 -> YES.
    // h(n) = 10n - a0. a0=100, n0=10. h(10) = 100-100=0.
    startTest(7);
    print_test(3, -10, 100, 3, 10);
    
    // Test 8: c > a2, but fails at n0 -> NO.
    // f(n)=n^2+10n, c=2, n0=5. We need n^2-10n >= 0. Fails for n=5.
    startTest(8);
    print_test(1, 10, 0, 2, 5);

    // Test 9: c > a2, holds at n0, but vertex is after n0 and dips -> NO.
    // h(n) = (c-a2)n^2 - a1n - a0.
    // Let h(n) = n^2 - 20n + 99. Vertex at n=10. Min value is h(10) = -1.
    // Let n0 = 1. h(1) = 1 - 20 + 99 = 80 > 0.
    // h'(1) = 2 - 20 = -18 < 0. So it fails.
    // This corresponds to c-a2=1, a1=20, a0=-99.
    startTest(9);
    print_test(5, 20, -99, 6, 1);

    // Test 10: c > a2, holds at n0, vertex is after n0 but does not dip below zero -> YES
    // h(n) = n^2 - 20n + 100 = (n-10)^2. Min value is 0.
    // This corresponds to c-a2=1, a1=20, a0=-100.
    startTest(10);
    print_test(5, 20, -100, 6, 1);

    // Test 11: All zero coefficients, should be YES.
    startTest(11);
    print_test(0, 0, 0, 1, 1);

    // --- Randomized Cases ---
    const int A_MIN = -100, A_MAX = 100;
    const int C_MIN = 1, C_MAX = 100;
    const int N0_MIN = 1, N0_MAX = 100;

    for (int i = 12; i <= 30; ++i) {
        startTest(i);
        long long a2 = rnd.next(A_MIN, A_MAX);
        long long a1 = rnd.next(A_MIN, A_MAX);
        long long a0 = rnd.next(A_MIN, A_MAX);
        long long c = rnd.next(C_MIN, C_MAX);
        long long n0 = rnd.next(N0_MIN, N0_MAX);
        print_test(a2, a1, a0, c, n0);
    }
    
    // --- Targeted Randomized Cases ---

    // Case: c > a2
    for (int i = 31; i <= 40; ++i) {
        startTest(i);
        long long c = rnd.next(C_MIN + 1, C_MAX);
        long long a2 = rnd.next(A_MIN, c - 1);
        long long a1 = rnd.next(A_MIN, A_MAX);
        long long a0 = rnd.next(A_MIN, A_MAX);
        long long n0 = rnd.next(N0_MIN, N0_MAX);
        print_test(a2, a1, a0, c, n0);
    }

    // Case: c == a2
    for (int i = 41; i <= 50; ++i) {
        startTest(i);
        long long c = rnd.next(C_MIN, C_MAX);
        long long a2 = c;
        long long a1 = rnd.next(A_MIN, A_MAX);
        long long a0 = rnd.next(A_MIN, A_MAX);
        long long n0 = rnd.next(N0_MIN, N0_MAX);
        print_test(a2, a1, a0, c, n0);
    }
    
    // Case: c < a2
    for (int i = 51; i <= 60; ++i) {
        startTest(i);
        long long a2 = rnd.next(A_MIN + 1, A_MAX);
        long long c = rnd.next(C_MIN, min((long long)C_MAX, a2 - 1));
        long long a1 = rnd.next(A_MIN, A_MAX);
        long long a0 = rnd.next(A_MIN, A_MAX);
        long long n0 = rnd.next(N0_MIN, N0_MAX);
        print_test(a2, a1, a0, c, n0);
    }


    return 0;
}