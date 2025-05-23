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
    vector<int> boxes(n);

    for (auto &box : boxes)
    {
        cin >> box;
    }

    vector<int> lis;

    for (const auto &box : boxes)
    {
        auto it = std::lower_bound(lis.begin(), lis.end(), box);
        if (it == lis.end())
        {
            lis.push_back(box);
        }
        else
        {
            *it = box;
        }
    }

    cout << lis.size() << "\n";

    return 0;
}