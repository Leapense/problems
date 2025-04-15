#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    int X;
    cin >> N >> M >> K >> X;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> rating(N + 1);
    rating[0] = X;
    for (int i = 1; i <= N; i++) {
        rating[i] = rating[i - 1] + A[i - 1];
    }

    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + (rating[i] < K ? 1 : 0);
    }

    while (M--) {
        int l, r;
        cin >> l >> r;

        int ans = prefix[r - 1] - prefix[l - 1];
        cout << ans << "\n";
    }

    return 0;
}