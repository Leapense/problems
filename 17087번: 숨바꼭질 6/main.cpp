#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, S;
    std::cin >> N >> S;

    std::vector<int> positions(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> positions[i];
    }

    int result = abs(positions[0] - S);

    for (int i = 1; i < N; i++)
    {
        int diff = abs(positions[i] - S);
        result = std::gcd(result, diff);
    }

    std::cout << result << "\n";

    return 0;
}