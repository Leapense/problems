#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> categories(N);
    vector<int> counts(N, 0);

    unordered_map<string, vector<int>> keywordToCategory;

    for (int i = 0; i < N; i++)
    {
        string catName;
        int W;
        cin >> catName >> W;

        categories[i] = catName;
        for (int j = 0; j < W; j++)
        {
            string keyword;
            cin >> keyword;
            keywordToCategory[keyword].push_back(i);
        }
    }

    string word;
    while (cin >> word)
    {
        if (keywordToCategory.count(word))
        {
            for (int idx : keywordToCategory[word])
            {
                counts[idx]++;
            }
        }
    }

    int maxCount = 0;
    for (int count : counts)
    {
        maxCount = max(maxCount, count);
    }

    vector<string> result;
    for (int i = 0; i < N; i++)
    {
        if (counts[i] == maxCount)
        {
            result.push_back(categories[i]);
        }
    }

    sort(result.begin(), result.end());
    for (const string &cat : result)
    {
        cout << cat << "\n";
    }

    return 0;
}