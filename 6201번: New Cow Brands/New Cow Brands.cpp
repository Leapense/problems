#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int N;
long long S, F;
vector<string> allowed;
vector<unordered_map<int, long long>> memo;
long long dp(int pos, int used)
{
    if (pos == N)
        return 1;
    if (memo[pos].count(used))
        return memo[pos][used];
    long long total = 0;
    for (char c : allowed[pos])
    {
        int bit = 1 << (c - 'A');
        if (used & bit)
            continue;
        total += dp(pos + 1, used | bit);
        if (total > F)
        {
            total = F;
            break;
        }
    }
    memo[pos][used] = total;
    return total;
}
string kth_code(long long k, int pos, int used, string prefix)
{
    if (pos == N)
        return prefix;
    for (char c : allowed[pos])
    {
        int bit = 1 << (c - 'A');
        if (used & bit)
            continue;
        long long cnt = dp(pos + 1, used | bit);
        if (k > cnt)
            k -= cnt;
        else
            return kth_code(k, pos + 1, used | bit, prefix + c);
    }
    return "";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S >> F;
    allowed.resize(N);
    for (int i = 0; i < N; i++)
        cin >> allowed[i];
    memo.resize(N + 1);
    for (long long i = S; i <= F; i++)
    {
        cout << kth_code(i, 0, 0, "") << "\n";
    }
    return 0;
}
