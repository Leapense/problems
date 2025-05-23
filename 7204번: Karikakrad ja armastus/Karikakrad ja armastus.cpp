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
    vector<int> L(N);
    for (int &x : L) cin >> x;

    int current_gcd = L[0];
    for (int i = 1; i < N; ++i) {
        current_gcd = gcd(current_gcd, L[i]);
    }

    if(current_gcd > 1) {
        cout << current_gcd;
    } else {
        cout << 1;
    }

    return 0;
}