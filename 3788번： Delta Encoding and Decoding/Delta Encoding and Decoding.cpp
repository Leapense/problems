#include <bits/stdc++.h>
using namespace std;

static const string DEFAULT_CIPHER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool setCipher(const string &raw, string &cipher, vector<int> &value)
{
    string filtered;
    for (char c : raw)
    {
        if (isalpha(c))
            filtered.push_back(toupper(c));
    }
    if (filtered.size() != 26)
        return false;
    vector<bool> seen(26, false);
    for (char c : filtered)
    {
        if (seen[c - 'A'])
            return false;
        seen[c - 'A'] = true;
    }
    cipher = filtered;
    for (int i = 0; i < 26; i++)
    {
        value[cipher[i] - 'A'] = i;
    }
    return true;
}

string encryptText(const string &text, const string &cipher, const vector<int> &value)
{
    string result;
    char prev = 'A';
    for (char c : text)
    {
        if (!isalpha(c))
        {
            result.push_back(c);
            prev = 'A';
        }
        else
        {
            int currVal = value[toupper(c) - 'A'];
            int prevVal = value[toupper(prev) - 'A'];
            int diff = (currVal - prevVal + 26) % 26;
            char enc = cipher[diff];
            if (isupper(c))
                enc = toupper(enc);
            else
                enc = tolower(enc);
            result.push_back(enc);
            prev = c;
        }
    }
    return result;
}

string decryptText(const string &text, const string &cipher, const vector<int> &value)
{
    string result;
    char prev = 'A';
    for (char c : text)
    {
        if (!isalpha(c))
        {
            result.push_back(c);
            prev = 'A';
        }
        else
        {
            int encVal = value[toupper(c) - 'A'];
            int prevVal = value[toupper(prev) - 'A'];
            int origVal = (prevVal + encVal) % 26;
            char dec = cipher[origVal];
            if (isupper(c))
                dec = toupper(dec);
            else
                dec = tolower(dec);
            result.push_back(dec);
            prev = dec;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string currentCipher = DEFAULT_CIPHER;
    vector<int> value(26);
    for (int i = 0; i < 26; i++)
    {
        value[DEFAULT_CIPHER[i] - 'A'] = i;
    }

    string line;
    while (true)
    {
        if (!std::getline(cin, line))
            break;
        if (line.empty())
            continue;
        stringstream ss(line);
        string command;
        ss >> command;
        for (auto &ch : command)
            ch = toupper(ch);

        if (command == "ENCRYPT")
        {
            ss.ignore(numeric_limits<streamsize>::max(), ' ');
            string remaining;
            getline(ss, remaining);
            string output = encryptText(remaining, currentCipher, value);
            cout << "RESULT:  " << output << "\n";
        }
        else if (command == "DECRYPT")
        {
            ss.ignore(numeric_limits<streamsize>::max(), ' ');
            string remaining;
            getline(ss, remaining);
            string output = decryptText(remaining, currentCipher, value);
            cout << "RESULT:  " << output << "\n";
        }
        else if (command == "CIPHER")
        {
            string remaining;
            getline(ss, remaining);
            string tmpCipher;
            vector<int> tmpValue(26);
            if (!setCipher(remaining, tmpCipher, tmpValue))
            {
                cout << "Bad cipher.  Using default.\n";
                currentCipher = DEFAULT_CIPHER;
                for (int i = 0; i < 26; i++)
                {
                    value[DEFAULT_CIPHER[i] - 'A'] = i;
                }
            }
            else
            {
                currentCipher = tmpCipher;
                value = tmpValue;
                cout << "Good cipher.  Using " << currentCipher << ".\n";
            }
        }
        else
        {
            cout << "Command not understood.\n";
        }
    }
    return 0;
}
