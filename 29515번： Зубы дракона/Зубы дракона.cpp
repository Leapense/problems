#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> top(n), bot(n);

    for (int i = 0; i < n; i++)
    {
        cin >> top[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> bot[i];
    }

    for (int offset = 0; offset <= n; offset++)
    {
        bool valid = true;
        for (int i = offset; i < n; i++)
        {
            if (top[i] + bot[i - offset] > d)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << offset;
            return 0;
        }

        if (offset > 0)
        {
            valid = true;
            for (int i = 0; i < n - offset; i++)
            {
                if (top[i] + bot[i + offset] > d)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                cout << offset;
                return 0;
            }
        }
    }

    return 0;
}