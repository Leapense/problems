#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> colors(n);
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }

    vector<bool> used(n, false);
    unordered_set<int> chosenColors;
    vector<int> answer;

    for (int i = 0; i < n && answer.size() < k; i++)
    {
        if (chosenColors.find(colors[i]) == chosenColors.end())
        {
            chosenColors.insert(colors[i]);
            answer.push_back(colors[i]);
            used[i] = true;
        }
    }

    for (int i = 0; i < n && answer.size() < k; i++)
    {
        if (!used[i])
        {
            answer.push_back(colors[i]);
            used[i] = true;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << (i + 1 == answer.size() ? "\n" : " ");
    }

    return 0;
}