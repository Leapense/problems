#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < N; i++)
    {
        pos[A[i]].push_back(i);
    }

    int ans = 0;

    for (auto &entry : pos)
    {
        vector<int> &indices = entry.second;
        int sz = indices.size();
        int i = 0;

        for (int j = 0; j < sz; j++)
        {
            while (indices[j] - indices[i] - (j - i) > K)
            {
                i++;
            }

            ans = max(ans, j - i + 1);
        }
    }

    cout << ans << "\n";
    return 0;
}