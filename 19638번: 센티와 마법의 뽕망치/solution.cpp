#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    long long Hc;
    cin >> N >> Hc >> T;
    priority_queue<long long> pq;
    for (int i = 0; i < N; i++) {
        long long h;
        cin >> h;
        pq.push(h);
    }

    int used = 0;
    for (int i = 0; i < T; i++) {
        if (pq.empty()) break;
        long long top = pq.top();
        if (top < Hc) {
            cout << "YES\n" << used << "\n";
            return 0;
        }
        if (top == 1) break;
        pq.pop();
        pq.push(top / 2);
        used++;
    }

    if (!pq.empty() && pq.top() < Hc) {
        cout << "YES\n" << used << "\n";
    } else {
        long long mx = pq.empty() ? 0 : pq.top();
        cout << "NO\n" << mx << "\n";
    }

    return 0;
}