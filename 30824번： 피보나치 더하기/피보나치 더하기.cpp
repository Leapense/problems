#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<unsigned long long> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (true)
    {
        unsigned long long nxt = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (nxt > 10000000000000000ULL)
            break;
        fib.push_back(nxt);
    }

    int T;
    cin >> T;

    while (T--)
    {
        int k;
        unsigned long long x;
        cin >> k >> x;
        bool possible = false;

        if (k == 1)
        {
            if (binary_search(fib.begin(), fib.end(), x))
                possible = true;
        }
        else if (k == 2)
        {
            for (auto a : fib)
            {
                if (a > x)
                    break;
                unsigned long long remain = x - a;
                if (binary_search(fib.begin(), fib.end(), remain))
                {
                    possible = true;
                    break;
                }
            }
        }
        else if (k == 3)
        {
            for (auto a : fib)
            {
                if (a > x)
                    break;
                for (auto b : fib)
                {
                    if (a + b > x)
                        break;
                    unsigned long long remain = x - a - b;
                    if (remain < 1)
                        continue;
                    if (binary_search(fib.begin(), fib.end(), remain))
                    {
                        possible = true;
                        break;
                    }
                }

                if (possible)
                    break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}