#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    priority_queue<int> pq;

    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        pq.push(c);
    }

    vector<int> wants(M);
    for (int i = 0; i < M; ++i) {
        cin >> wants[i];
    }

    for (int i = 0; i < M; ++i) {
        int w = wants[i];
        if (pq.empty()) {
            cout << 0 << "\n";
            return 0;
        }

        int top = pq.top(); pq.pop();
        if (top < w) {
            cout << 0 << "\n";
            return 0;
        }

        top -= w;
        if (top > 0) pq.push(top);
    }

    cout << 1 << "\n";
    return 0;
}
