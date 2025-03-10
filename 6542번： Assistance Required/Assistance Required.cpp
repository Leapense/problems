#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maxNum = 35000;
    vector<int> v;
    for (int i = 2; i <= maxNum; i++)
    {
        v.push_back(i);
    }

    vector<int> lucky;
    int idx = 0;

    while (idx < v.size())
    {
        int step = v[idx];
        lucky.push_back(v[idx]);
        if (lucky.size() >= 3000)
            break;

        vector<int> newv;
        for (int j = 0; j <= idx; j++)
        {
            newv.push_back(v[j]);
        }

        int count = 0;
        for (int j = idx + 1; j < v.size(); j++)
        {
            count++;
            if (count % step != 0)
            {
                newv.push_back(v[j]);
            }
        }
        v = newv;
        idx++;
    }

    int n;
    while (cin >> n && n)
    {
        cout << lucky[n - 1] << "\n";
    }

    return 0;
}