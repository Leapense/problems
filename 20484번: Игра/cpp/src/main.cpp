#include "main.h"
#include <iostream>
#include <string>
#include <vector>

// solveGame 함수는 앞서 설명한 DP 접근법을 사용합니다.
std::string solveGame(const std::string &n)
{
    int L = n.size();
    std::vector<bool> dp(L + 1, false);

    // 마지막 자리에서는 해당 턴의 플레이어(마지막으로 숫자를 채우는 플레이어)가 항상 승리합니다.
    dp[L] = true;

    // 뒤에서부터 각 자릿수를 채울 때의 승리 여부를 결정합니다.
    for (int i = L - 1; i >= 1; i--)
    {
        bool win = false;

        // [1] "동일 선택": 현재 자리에서 n[i-1]와 같은 숫자를 선택하면 다음 턴 결과의 반대가 됩니다.
        if (!dp[i + 1])
        {
            win = true;
        }

        // [2] "상승 편차": n[i-1]가 '9'보다 작다면, n[i-1]보다 큰 숫자를 선택할 수 있습니다.
        // 이 경우 승패는 현재 플레이어가 마지막 플레이어(last mover)인지에 따라 결정됩니다.
        if (!win && n[i - 1] < '9')
        {
            // 현재 턴의 플레이어는 i번째에 해당하며, i의 홀짝과 전체 자릿수 L의 홀짝이 같으면 마지막 플레이어입니다.
            if ((i % 2) == (L % 2))
            {
                win = true;
            }
        }

        // [3] "하강 편차": n[i-1]가 허용 최소값(minAllowed)보다 크다면,
        // n[i-1]보다 작은 숫자를 선택할 수 있습니다. 이 경우 승패는 현재 플레이어가 마지막 플레이어가 아닌 경우 승리합니다.
        char minAllowed = (i == 1) ? '1' : '0';
        if (!win && n[i - 1] > minAllowed)
        {
            if ((i % 2) != (L % 2))
            {
                win = true;
            }
        }

        dp[i] = win;
    }

    return dp[1] ? "First" : "Second";
}

#ifndef UNIT_TESTS
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n;
    std::cin >> n;
    std::cout << solveGame(n) << "\n";
    return 0;
}
#endif