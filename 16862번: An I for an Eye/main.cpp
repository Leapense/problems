#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
    {
        number = number * 10 + c - 48;
    }
    if (negative)
    {
        number *= -1;
    }
}

struct Rule
{
    string pattern;
    char replacement;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    fastscan(n);
    cin.ignore();

    vector<Rule> rules = {
        {"at", '@'},
        {"and", '&'},
        {"one", '1'},
        {"won", '1'},
        {"to", '2'},
        {"too", '2'},
        {"two", '2'},
        {"for", '4'},
        {"four", '4'},
        {"bea", 'b'},
        {"be", 'b'},
        {"bee", 'b'},
        {"sea", 'c'},
        {"see", 'c'},
        {"eye", 'i'},
        {"oh", 'o'},
        {"owe", 'o'},
        {"are", 'r'},
        {"you", 'u'},
        {"why", 'y'}};

    for (int line = 0; line < n; ++line)
    {
        string s;
        getline(cin, s);
        string output;
        int i = 0;
        while (i < (int)s.size())
        {
            int bestLen = 0;
            char bestReplacement = '\0';
            // check each rule if it matches starting at position i
            for (auto &rule : rules)
            {
                int len = rule.pattern.size();
                if (i + len <= (int)s.size())
                {
                    bool match = true;
                    // check match case-insensitively
                    for (int j = 0; j < len; ++j)
                    {
                        if (tolower(s[i + j]) != rule.pattern[j])
                        {
                            match = false;
                            break;
                        }
                    }
                    // if matched and longer than previous, update best match
                    if (match && len > bestLen)
                    {
                        bestLen = len;
                        bestReplacement = rule.replacement;
                    }
                }
            }
            // If a rule matched, substitute
            if (bestLen > 0)
            {
                // If the first character is uppercase and replacement is alphabetic, change replacement to uppercase.
                if (isupper(s[i]) && isalpha(bestReplacement))
                {
                    bestReplacement = toupper(bestReplacement);
                }
                output.push_back(bestReplacement);
                i += bestLen; // skip the replaced substring
            }
            else
            {
                // No substitution: output the current character
                output.push_back(s[i]);
                ++i;
            }
        }
        cout << output;
        if (line < n - 1)
            cout << "\n";
    }
    return 0;
}