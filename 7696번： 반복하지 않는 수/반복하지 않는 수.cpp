#include <bits/stdc++.h>
using namespace std;

void backtrack(int num, int used, int length, vector<int> &v) {
    if (num > 0) {
        v.push_back(num);
    }
    if (length == 10) {
        return;
    }

    for (int d = 0; d <= 9; d++) {
        if (num == 0 && d == 0) {
            continue;
        }
        if (!(used & (1 << d))) {
            backtrack(num * 10 + d, used | (1 << d), length + 1, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    backtrack(0, 0, 0, v);
    int n;
    while(cin >> n && n != 0) {
        cout << v[n - 1] << "\n";
    }
    return 0;
}