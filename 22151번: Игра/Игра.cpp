#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int limit, sr, sc, er, ec;
    int dist;

    for (int i = 0; i < N; i++) {
        cin >> limit >> sr >> sc >> er >> ec;
        dist = abs(sr - er) + abs(sc - ec);

        if (dist <= limit) {
            cout << "First 1\n";
        } else {
            cout << "Infinity\n";
        }
    }

    return 0;
}