#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isClosing(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool isCommaOrSemicolon(char c)
{
    return c == ',' || c == ';';
}

bool isSpecial(char c)
{
    string specials = "()[]{}.,;:";
    return specials.find(c) != string::npos;
}

string canonicalize(const string &s)
{
    string lower;
    for (char c : s)
    {
        lower.push_back(tolower(c));
    }
    vector<string> tokens;
    int i = 0;

    while (i < (int)lower.size())
    {
        if (isspace((unsigned char)lower[i]))
        {
            i++;
        }
        else if (isalnum((unsigned char)lower[i]))
        {
            int start = i;
            while (i < (int)lower.size() && isalnum((unsigned char)lower[i]))
            {
                i++;
            }
            tokens.push_back(lower.substr(start, i - start));
        }
        else if (isSpecial(lower[i]))
        {
            string one(1, lower[i]);
            if (isOpening(lower[i]))
                one = "(";
            else if (isClosing(lower[i]))
                one = ")";
            else if (isCommaOrSemicolon(lower[i]))
                one = ",";
            tokens.push_back(one);
            i++;
        }
        else
        {
            string one(1, lower[i]);
            tokens.push_back(one);
            i++;
        }
    }

    vector<string> refined;
    for (int j = 0; j < (int)tokens.size(); j++)
    {
        if (tokens[j].size() == 1 && isSpecial(tokens[j][0]))
        {
            refined.push_back(tokens[j]);
        }
        else if (!tokens[j].empty())
        {
            refined.push_back(tokens[j]);
        }
    }

    vector<string> result;
    for (int j = 0; j < (int)refined.size(); j++)
    {
        if (j == 0)
        {
            result.push_back(refined[j]);
        }
        else
        {
            bool prevSpecial = (result.back().size() == 1 && isSpecial(result.back()[0]));
            bool currSpecial = (refined[j].size() == 1 && isSpecial(refined[j][0]));

            if (prevSpecial || currSpecial)
            {
                result.push_back(refined[j]);
            }
            else
            {
                result.push_back(" " + refined[j]);
            }
        }
    }

    string merged;
    for (auto &r : result)
    {
        merged += r;
    }

    return merged;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 1; i <= K; i++)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        string c1 = canonicalize(s1);
        string c2 = canonicalize(s2);
        cout << "Data Set " << i << ": ";
        if (c1 == c2)
            cout << "equal\n\n";
        else
            cout << "not equal\n\n";
    }

    return 0;
}