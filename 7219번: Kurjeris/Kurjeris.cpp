#ifdef LOCAL
void dbg() { cerr << "\n"; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); }
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; }
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else
#pragma GCC optimize("O3,unroll-loops")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
template<class T> bool chmin(T &a, T b) { return b < a and (a = b, true); }
template<class T> bool chmax(T &a, T b) { return b > a and (a = b, true); }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int N;
    cin >> N;

    vector<int> m(N);
    for (int &x : m) cin >> x;

    vector<long long> pos(N, 0);
    pos[0] = m[0];

    for (int i = 1; i < N; ++i) {
        pos[i] = pos[i - 1] + m[i];
    }

    int K;
    cin >> K;

    bool possible = true;
    long long max_pos = 0;

    for (int i = 0; i < K; ++i) {
        int ai;
        long long ti;
        cin >> ai >> ti;

        int city = ai - 1;
        if (city < 0 || city >= N) {
            possible = false;
        } else {
            long long city_pos = pos[city];
            if (city_pos > ti) {
                possible = false;
            } else {
                if (city_pos > max_pos) {
                    max_pos = city_pos;
                }
            }
        }
    }

    if (possible) {
        cout << 2 * max_pos;
    } else {
        cout << -1;
    }

    return 0;
}