#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    int idx = 0;
    for (; idx < k; ++idx)
    {
        pq.push(t[idx]);
    }

    long long current_time = 0, penalty = 0;

    while (!pq.empty())
    {
        int time_to_solve = pq.top();
        pq.pop();
        current_time += time_to_solve;
        penalty += current_time;

        if (idx < n)
        {
            pq.push(t[idx]);
            idx++;
        }
    }

    cout << penalty << endl;
    return 0;
}