#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<unsigned int> freq(1000001, 0);

    bool possible = false;
    for (int i = 0; i < N && !possible; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        freq[a]++;
        if (freq[a] >= 2) {
            possible = true;
        }

        freq[b]++;
        if(freq[b] >= 2) {
            possible = true;
        }

        freq[c]++;
        if (freq[c] >= 2) {
            possible = true;
        }
    }

    if (!possible) {
        for (int i = 0; i < N; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
        }
    }

    cout << (possible ? "1" : "0") << endl;

    return 0;
}