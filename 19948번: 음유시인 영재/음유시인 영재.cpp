#include <bits/stdc++.h>
using namespace std;

int main()
{
    string poem;
    getline(cin, poem);
    long long space_remaining;
    cin >> space_remaining;
    long long key_remaining[26];
    for (int i = 0; i < 26; i++)
        cin >> key_remaining[i];
    // Generate title
    vector<string> words;
    string word;
    for (char c : poem)
    {
        if (c != ' ')
            word += c;
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty())
        words.push_back(word);
    string title = "";
    for (auto &w : words)
    {
        if (!w.empty())
        {
            char first = toupper(w[0]);
            title += first;
        }
    }
    // Count key presses
    // Initialize usage
    long long space_used = 0;
    long long key_used[26];
    for (int i = 0; i < 26; i++)
        key_used[i] = 0;
    // Process poem
    char prev = 0;
    for (char c : poem)
    {
        if (c == prev)
        {
            continue;
        }
        if (c == ' ')
        {
            space_used++;
        }
        else
        {
            char upper = toupper(c);
            key_used[upper - 'A']++;
        }
        prev = c;
    }
    // Process title
    prev = 0;
    for (char c : title)
    {
        if (c == prev)
        {
            continue;
        }
        char upper = c;
        key_used[upper - 'A']++;
        prev = c;
    }
    // Check
    bool ok = true;
    if (space_used > space_remaining)
        ok = false;
    for (int i = 0; i < 26; i++)
        if (key_used[i] > key_remaining[i])
        {
            ok = false;
            break;
        }
    if (ok)
        cout << title;
    else
        cout << -1;

    return 0;
}
