#include <iostream>

long long binomial(int n, int k)
{
    if (k > n)
        return 0;
    if (k > n - k)
        k = n - k;

    long long result = 1;
    for (int i = 1; i <= k; i++)
    {
        result = result * (n - i + 1) / i;
    }

    return result;
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::cout << binomial(M - 1, N - 1) << "\n";
    return 0;
}