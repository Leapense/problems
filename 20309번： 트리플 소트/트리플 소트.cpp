#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if(((i + 1) & 1) != (arr[i] & 1)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}