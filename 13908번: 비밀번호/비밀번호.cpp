#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    set<char> required;

    for (int i = 0; i < m; i++)
    {
        char digit;
        cin >> digit;

        required.insert(digit);
    }

    long long count = 0;
    long long total = 1;

    for (int i = 0; i < n; i++)
    {
        total *= 10;
    }

    for (long long num = 0; num < total; num++)
    {
        string s = to_string(num);
        if (s.size() < n)
        {
            s = string(n - s.size(), '0') + s;
        }

        bool valid = true;

        for (char d : required)
        {
            if (s.find(d) == string::npos)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}