#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c = getchar();
    number = 0;

    while (c == ' ' || c == '\n')
        c = getchar();

    if (c == '-')
    {
        negative = true;
        c = getchar();
    }

    for (; c >= '0' && c <= '9'; c = getchar())
    {
        number = number * 10 + c - '0';
    }

    if (negative)
        number = -number;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    fastscan(n);

    vector<string> network(n);

    for (int i = 0; i < n; i++)
    {
        string row;
        row.reserve(n);

        while ((int)row.size() < n)
        {
            char ch = getchar();
            if (ch == '+' || ch == '-' || ch == '0')
            {
                row.push_back(ch);
            }
        }

        network[i] = row;
    }

    int m;
    fastscan(m);

    for (int i = 0; i < m; i++)
    {
        int b, c;
        fastscan(b);
        fastscan(c);

        cout << network[b][c] << "\n";
    }

    return 0;
}