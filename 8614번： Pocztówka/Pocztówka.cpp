#include <iostream>
#include <vector>

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> h(n);

    for (long long i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    long long total_subarrays = n * (n + 1) / 2;
    long long total_subarrays_without = 0;
    long long count = 0;

    for (long long i = 0; i < n; ++i) {
        if (h[i] < m) {
            count++;
        } else {
            total_subarrays_without += count * (count + 1) / 2;
            count = 0;
        }
    }

    if (count > 0) {
        total_subarrays_without += count * (count + 1) / 2;
    }

    long long ans = total_subarrays - total_subarrays_without;
    std::cout << ans << std::endl;

    return 0;
}