#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::vector<int> dp(N, 0);

    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        dp[i] = A[i];

        for (int j = 0; j < i; ++j)
        {
            if (A[j] > A[i])
            {
                dp[i] = std::max(dp[i], dp[j] + A[i]);
            }
        }

        answer = std::max(answer, dp[i]);
    }

    std::cout << answer << "\n";

    return 0;
}