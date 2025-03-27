#include <iostream>
#include <vector>
#include <algorithm>

void optimize_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main()
{
    optimize_io();
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    std::vector<long long> b(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> b[i];
    }

    if (n == 0)
    {
        std::cout << 0 << "\n";
        return 0;
    }

    long long dp_drag = a[0];
    long long dp_carry = b[0];

    for (int i = 1; i < n; ++i)
    {
        long long next_drag = std::min(dp_drag + a[i], dp_carry + k + a[i]);
        long long next_carry = std::min(dp_carry + b[i], dp_drag + k + b[i]);

        dp_drag = next_drag;
        dp_carry = next_carry;
    }

    std::cout << std::min(dp_drag, dp_carry) << "\n";

    return 0;
}