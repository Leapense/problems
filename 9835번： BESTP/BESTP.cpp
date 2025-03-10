#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input, all;
    while (getline(cin, input))
        all += input;
    string filtered;
    for (char ch : all)
    {
        if (!isspace(static_cast<unsigned char>(ch)))
            filtered.push_back(ch);
    }
    vector<string> machines;
    string current;
    for (char ch : filtered)
    {
        if (ch == ',' || ch == '.')
        {
            if (!current.empty())
            {
                machines.push_back(current);
                current.clear();
            }
        }
        else
        {
            current.push_back(ch);
        }
    }
    for (auto &machine : machines)
    {
        int max_sum = -1000000000, current_sum = 0;
        for (char ch : machine)
        {
            int value = 0;
            if (ch == 'o')
                value = 100;
            else if (ch == 'e')
                value = 10;
            else if (ch == 'g')
                value = 1;
            else if (ch == 'a')
                value = 0;
            else if (ch == 'b')
                value = -1;
            else if (ch == 'i')
                value = -10;
            else if (ch == 'u')
                value = -100;
            current_sum = max(value, current_sum + value);
            max_sum = max(max_sum, current_sum);
        }
        cout << (max_sum < 0 ? 0 : max_sum) << "\n";
    }
    return 0;
}
