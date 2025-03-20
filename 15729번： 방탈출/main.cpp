#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> target(n), state(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> target[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (state[i] != target[i])
        {
            count++;
            state[i] ^= 1;
            if (i + 1 < n)
                state[i + 1] ^= 1;
            if (i + 2 < n)
                state[i + 2] ^= 1;
        }
    }

    cout << count << "\n";

    return 0;
}