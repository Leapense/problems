#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int R, n;
        if (!(cin >> R >> n)) {
            return 0;
        }

        if (R == -1 && n == -1) {
            break;
        }

        vector<int> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        int ans = 0;
        int i = 0;

        while (i < n) {
            int start = x[i];
            int j = i;

            while (j < n && x[j] <= start + R) {
                ++j;
            }

            int center = x[j - 1];

            int k = j;
            while (k < n && x[k] <= center + R) {
                ++k;
            }

            ++ans;
            i = k;
        }

        cout << ans << "\n";
    }

    return 0;
}