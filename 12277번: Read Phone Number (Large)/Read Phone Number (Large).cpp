#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string digitToWord(char d)
{
    switch (d)
    {
    case '0':
        return "zero";
    case '1':
        return "one";
    case '2':
        return "two";
    case '3':
        return "three";
    case '4':
        return "four";
    case '5':
        return "five";
    case '6':
        return "six";
    case '7':
        return "seven";
    case '8':
        return "eight";
    case '9':
        return "nine";
    }

    return "";
}

string countToWord(int count)
{
    switch (count)
    {
    case 2:
        return "double";
    case 3:
        return "triple";
    case 4:
        return "quadruple";
    case 5:
        return "quintuple";
    case 6:
        return "sextuple";
    case 7:
        return "septuple";
    case 8:
        return "octuple";
    case 9:
        return "nonuple";
    case 10:
        return "decuple";
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        string number, format;
        cin >> number >> format;
        vector<int> splits;

        stringstream ss(format);
        int num;
        char ch;
        while (ss >> num)
        {
            splits.push_back(num);
            ss >> ch;
        }

        vector<string> words;
        int idx = 0;
        for (int split : splits)
        {
            int end = idx + split;
            while (idx < end)
            {
                char cur = number[idx];
                int count = 0;
                int j = idx;
                while (j < end && number[j] == cur)
                {
                    count++;
                    j++;
                }

                if (count >= 2 && count <= 10)
                {
                    words.push_back(countToWord(count));
                    words.push_back(digitToWord(cur));
                }
                else if (count > 10)
                {
                    for (int k = idx; k < j; k++)
                    {
                        words.push_back(digitToWord(number[k]));
                    }
                }
                else
                {
                    words.push_back(digitToWord(cur));
                }
                idx = j;
            }
        }

        cout << "Case #" << tc << ":";
        for (auto &w : words)
            cout << " " << w;
        cout << "\n";
    }

    return 0;
}