#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> dict;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        if (word.size() <= 10)
        {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            dict.insert(sortedWord);
        }
    }

    int M;
    cin >> M;
    while (M--)
    {
        int P;
        cin >> P;
        vector<pair<char, int>> tiles(P);
        for (int i = 0; i < P; i++)
        {
            cin >> tiles[i].first >> tiles[i].second;
        }

        int ans = 0;
        int subsets = 1 << P;
        for (int mask = 1; mask < subsets; mask++)
        {
            string subsetLetters = "";
            int score = 0;
            for (int i = 0; i < P; i++)
            {
                if (mask & (1 << i))
                {
                    subsetLetters.push_back(tiles[i].first);
                    score += tiles[i].second;
                }
            }

            sort(subsetLetters.begin(), subsetLetters.end());
            if (dict.find(subsetLetters) != dict.end())
            {
                ans = max(ans, score);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}