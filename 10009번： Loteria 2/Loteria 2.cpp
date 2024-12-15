#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int changes = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == a[i + 1]) {
            changes++;
            int j = i + 1;
            while (j < n && a[j] == a[i]) {
                j++;
            }

            if (j < n) {
                int distinct = 0;
                if (i > 0 && a[i - 1] != a[j]) distinct = 2;
                else distinct = 1;

                if (k > distinct) {
                    for (int l = i + 1; l < j; l += 2) a[l] = -1;
                } else {
                    for (int l = i + 1; l < j; l++) a[l] = -1;
                }
            }
            else {
                for (int l = i + 1; l < j; l += 2) a[l] = -1;
            }
            i = j - 1;
        }
    }

    cout << changes << endl;

    return 0;
}