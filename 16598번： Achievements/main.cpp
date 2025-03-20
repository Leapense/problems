#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> days(n);

    for (int i = 0; i < n; i++)
        cin >> days[i];

    int max_streak = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        while (days[right] - days[left] - (right - left) > p)
        {
            left++;
        }

        int current_streak = days[right] - days[left] + 1;

        int used = days[right] - days[left] - (right - left);
        current_streak += (p - used);
        max_streak = max(max_streak, current_streak);
    }

    cout << max_streak << "\n";

    return 0;
}