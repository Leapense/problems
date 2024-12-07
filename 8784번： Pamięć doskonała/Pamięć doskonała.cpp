#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Z;
    cin >> Z;

    while(Z--) {
        int N;
        cin >> N;
        vector<long long> S(N), P(N), A(N);
        for (int i = 0; i < N; i++) cin >> S[i];

        bool ok = true;
        for (int i = 0; i < N / 2; i++) {
            long long x = S[i], y = S[N - 1 - i];
            if (((x + y) % 2) != 0 || ((x - y) % 2) != 0) {
                ok = false;
                break;
            }

            long long pp = (x + y) / 2;
            long long aa = (x - y) / 2;
            P[i] = pp;
            P[N - 1 - i] = pp;
            A[i] = aa;
            A[N - 1 - i] = -aa;
        }

        if (!ok) {
            cout << "NIE\n";
            continue;
        }

        for (int i = 0; i < N; i++) cout << P[i] << " ";
        cout << "\n";
        for (int i = 0; i < N; i++) cout << A[i] << " ";
        cout << "\n";
    }

    return 0;
}