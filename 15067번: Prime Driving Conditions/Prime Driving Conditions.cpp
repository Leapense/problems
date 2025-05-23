#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(10000, true);

void sieve()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 10000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < 10000; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

string next_plate(string letters)
{
    for (int i = 2; i >= 0; i--)
    {
        if (letters[i] < 'Z')
        {
            letters[i]++;
            for (int j = i + 1; j <= 2; j++)
            {
                letters[j] = 'A';
            }
            return letters;
        }
    }

    return "ZZZ";
}

int main()
{
    sieve();
    string s;
    int num;

    while (cin >> s >> num)
    {
        if (s == "END" && num == 0)
            break;
        while (true)
        {
            for (int i = num; i < 10000; i++)
            {
                if (prime[i])
                {
                    cout << s << ' ' << setw(4) << setfill('0') << i << "\n";
                    goto next_case;
                }
            }
            s = next_plate(s);
            num = 0;
        }
    next_case:;
    }

    return 0;
}