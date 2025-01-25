#include <bits/stdc++.h>
using namespace std;

class BessieBlocks
{
public:
    int N;
    vector<string> blocks;
    vector<string> words;

    BessieBlocks()
    {
        cin >> N;
        blocks.resize(4);
        for (int i = 0; i < 4; i++)
            cin >> blocks[i];
        words.resize(N);
        for (int i = 0; i < N; i++)
            cin >> words[i];
    }

    bool canSpellWord(const string &word)
    {
        int L = word.length();
        vector<bool> used(4, false);
        return backtrack(word, 0, used);
    }

    bool backtrack(const string &word, int index, vector<bool> &used)
    {
        if (index == word.length())
            return true;
        for (int i = 0; i < 4; i++)
        {
            if (!used[i] && blocks[i].find(word[index]) != string::npos)
            {
                used[i] = true;
                if (backtrack(word, index + 1, used))
                    return true;
                used[i] = false;
            }
        }

        return false;
    }

    void solve()
    {
        for (auto &word : words)
        {
            cout << (canSpellWord(word) ? "YES" : "NO") << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    BessieBlocks bb;
    bb.solve();
}