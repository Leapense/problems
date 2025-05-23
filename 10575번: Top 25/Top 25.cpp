#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<string> list1(n), list2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> list1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> list2[i];
        }

        unordered_map<string, int> idMap;
        int idCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (idMap.find(list1[i]) == idMap.end())
            {
                idMap[list1[i]] = idCount++;
            }
        }

        vector<int> diff(idCount, 0);
        int nonzero = 0;
        vector<int> ans;

        int segStart = 0;
        for (int i = 0; i < n; i++)
        {
            int idxA = idMap[list1[i]];
            int prevA = diff[idxA];
            diff[idxA]++;
            if (prevA == 0 && diff[idxA] != 0)
            {
                nonzero++;
            }
            else if (prevA != 0 && diff[idxA] == 0)
            {
                nonzero--;
            }

            int idxB = idMap[list2[i]];
            int prevB = diff[idxB];
            diff[idxB]--;

            if (prevB == 0 && diff[idxB] != 0)
            {
                nonzero++;
            }
            else if (prevB != 0 && diff[idxB] == 0)
            {
                nonzero--;
            }
            if (nonzero == 0)
            {
                ans.push_back(i - segStart + 1);
                segStart = i + 1;
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}