#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<int> res;
    int mid = (n - 1) / 2;
    res.push_back(t[mid]);

    int left = mid - 1, right = mid + 1;
    bool toggle = true;
    while (left >= 0 || right < n)
    {
        if (toggle)
        {
            if (right < n)
            {
                res.push_back(t[right]);
                right++;
            }
            toggle = false;
        }
        else
        {
            if (left >= 0)
            {
                res.push_back(t[left]);
                left--;
            }

            toggle = true;
        }
    }

    for (auto &num : res)
    {
        cout << num << " ";
    }

    cout << "\n";
    return 0;
}