#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> corridor(201, 0);
        for (int i = 0; i < N; i++)
        {
            int s, t;
            cin >> s >> t;
            int a = (min(s, t) + 1) / 2;
            int b = (max(s, t) + 1) / 2;
            for (int j = a; j <= b; j++)
            {
                corridor[j]++;
            }
        }

        int maxCount = *max_element(corridor.begin(), corridor.end());
        cout << maxCount * 10 << "\n";
    }

    return 0;
}