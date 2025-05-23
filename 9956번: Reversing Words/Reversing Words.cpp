#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;

    while (getline(cin, line))
    {
        if (line == "#")
            break;
        istringstream iss(line);
        string token;
        string result;
        int pos = 0;
        vector<pair<int, int>> whitespace;
        vector<string> tokens;
        vector<int> startPos;
        int i = 0;
        while (i < (int)line.size())
        {
            if (isspace(line[i]))
            {
                result.push_back(line[i]);
                i++;
            }
            else
            {
                int j = i;
                while (j < (int)line.size() && !isspace(line[j]))
                    j++;
                tokens.push_back(line.substr(i, j - i));
                startPos.push_back(result.size());
                for (int k = 0; k < j - i; k++)
                {
                    result.push_back('#');
                }

                i = j;
            }
        }

        for (int t = 0; t < tokens.size(); t++)
        {
            string word = tokens[t];
            int letterCount = 0;
            for (auto c : word)
                if (isalpha(c))
                    letterCount++;
            if (letterCount < 2)
            {
                for (int k = 0; k < (int)word.size(); k++)
                {
                    result[startPos[t] + k] = word[k];
                }
                continue;
            }

            vector<char> letters;
            for (auto c : word)
                if (isalpha(c))
                    letters.push_back(c);
            reverse(letters.begin(), letters.end());
            int li = 0;
            for (int k = 0; k < (int)word.size(); k++)
            {
                if (isalpha(word[k]))
                {
                    char ch = letters[li++];
                    if (isupper(word[k]))
                        ch = toupper(ch);
                    else
                        ch = tolower(ch);
                    result[startPos[t] + k] = ch;
                }
                else
                {
                    result[startPos[t] + k] = word[k];
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}