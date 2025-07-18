#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    cin >> N >> A >> B;
    vector<long long> a(A), b(B);
    for (int i = 0; i < A; i++) cin >> a[i];
    for (int i = 0; i < B; i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    vector<long long> as(A + 1), bs(B + 1);
    as[0] = 0;
    for (int i = 1; i <= A; i++) as[i] = as[i - 1] + a[i - 1];
    bs[0] = 0;
    for (int i = 1; i <= B; i++) bs[i] = bs[i - 1] + b[i - 1];

    long long ans = 0;
    int maxS = min(B, N / 2);
    for (int x = 0; x <= maxS; x++) {
        int y = N - 2 * x;
        if (y < 0 || y > A) continue;
        long long cur = bs[x] + as[y];
        if (cur > ans) ans = cur;
    }

    cout << ans << "\n";
    return 0;
}