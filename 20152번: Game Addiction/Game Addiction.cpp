#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

// Function to compute binomial coefficient: C(2n, n)
unsigned long long binomialCoefficient(int n)
{
    unsigned long long result = 1;
    // Compute binomial coefficient iteratively to avoid overflow.
    // C(2n, n) = (2n)! / (n! * n!) can be computed as:
    // result = Product(i=1 to n) of ((n+i)/i)
    for (int i = 1; i <= n; ++i)
    {
        result = result * (n + i) / i;
    }
    return result;
}

int main()
{
    int H, N;
    cin >> H >> N;

    // When start equals destination.
    if (H == N)
    {
        cout << 1;
        return 0;
    }

    int n = abs(N - H);
    // Calculate the Catalan number: C(n) = (1 / (n+1)) * binom(2n, n)
    unsigned long long catalan = binomialCoefficient(n) / (n + 1);
    cout << catalan;

    return 0;
}
