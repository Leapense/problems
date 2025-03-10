#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool firstCase = true;
    while (true)
    {
        int n;
        if (!(cin >> n))
            break;
        cin.ignore();
        unordered_map<string, int> freq;
        string line;
        while (getline(cin, line))
        {
            if (line == "EndOfText")
                break;
            for (auto &ch : line)
            {
                if (isalpha(ch))
                    ch = tolower(ch);
                else
                    ch = ' ';
            }

            istringstream iss(line);
            string word;
            while (iss >> word)
            {
                freq[word]++;
            }
        }

        vector<string> result;
        for (auto &p : freq)
        {
            if (p.second == n)
                result.push_back(p.first);
        }

        sort(result.begin(), result.end());
        if (!firstCase)
            cout << "\n";
        firstCase = false;
        if (result.empty())
        {
            cout << "There is no such word." << "\n";
        }
        else
        {
            for (auto &w : result)
            {
                cout << w << "\n";
            }
        }
    }

    return 0;
}