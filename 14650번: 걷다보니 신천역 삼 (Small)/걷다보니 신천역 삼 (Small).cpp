#include <iostream>
using namespace std;

int N, ans;

void dfs(int pos, int sum)
{
    if (pos == N)
    {
        if (sum % 3 == 0)
            ans++;
        return;
    }
    for (int d = 0; d < 3; d++)
    {
        if (pos == 0 && d == 0)
            continue;
        dfs(pos + 1, sum + d);
    }
}

int main()
{
    cin >> N;
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}