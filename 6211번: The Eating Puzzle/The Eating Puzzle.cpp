#include <iostream>
#include <vector>

using namespace std;

int C, B, best = 0;
vector<int> buckets;

void dfs(int index, int sum)
{
    if (sum > C)
        return;
    if (sum > best)
        best = sum;
    if (index == B)
        return;
    dfs(index + 1, sum + buckets[index]);
    dfs(index + 1, sum);
}

int main()
{
    cin >> C >> B;
    buckets.resize(B);
    for (int i = 0; i < B; i++)
    {
        cin >> buckets[i];
    }
    dfs(0, 0);
    cout << best;
    return 0;
}