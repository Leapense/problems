#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string baseline(100, '2'); // 100×Scissors, never modified
    cout << "? " << baseline << '\n'
         << flush;

    int K;
    if (!(cin >> K))
        return 0; // safety: judge closed

    vector<int> W(100);

    for (int i = 0; i < 100; ++i)
    {
        string q = baseline; // fresh copy
        q[i] = '0';          // rock at position i
        cout << "? " << q << '\n'
             << flush;
        cin >> W[i];
    }

    string machine(100, '0'); // default “Rock”

    for (int i = 0; i < 100; ++i)
    {
        int d = W[i] - K;
        if (d == -1)
            machine[i] = '5'; // Paper
        else if (d == 1)
            machine[i] = '2'; // Scissors
        // d==0 already mapped to '0'
    }

    cout << "! " << machine << '\n'
         << flush;
    return 0;
}
