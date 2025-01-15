#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int next_arr[MAX];
int prev_arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &x : A) cin >> x;

    int head = 0;
    int tail = N + 1;
    next_arr[head] = tail;
    prev_arr[tail] = head;

    int current = 1;

    for (int i = N - 1; i >= 0; i--) {
        int op = A[i];
        if (op == 1) {
            next_arr[current] = next_arr[head];
            prev_arr[current] = head;
            prev_arr[next_arr[head]] = current;
            next_arr[head] = current;
        }
        else if (op == 2) {
            int after = next_arr[head];
            next_arr[current] = next_arr[after];
            prev_arr[current] = after;
            prev_arr[next_arr[after]] = current;
            next_arr[after] = current;
        }
        else if (op == 3) {
            int before_tail = prev_arr[tail];
            next_arr[current] = next_arr[before_tail];
            prev_arr[current] = before_tail;
            prev_arr[next_arr[before_tail]] = current;
            next_arr[before_tail] = current;
        }
        current++;
    }

    vector<int> res;
    int node = next_arr[head];
    while(node != tail) {
        res.push_back(node);
        node = next_arr[node];
    }

    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }

    cout << "\n";
    return 0;
}