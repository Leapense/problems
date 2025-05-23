#ifdef LOCAL    // =========== Local ===========
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else            // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
template<class T> bool chmin(T &a, T b) { return b < a and (a = b, true); }
template<class T> bool chmax(T &a, T b) { return b > a and (a = b, true); } 

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int x, y;

    cin >> x >> y;

    for (int i = x; i >= 0; i--) printf("%d %d\n", i, y);
    for (int i = y - 1; i >= 0; i--) printf("0 %d\n", i);
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) printf("%d %d\n", i, j);
        for (int j = 8; j >= 0; j--) printf("%d %d\n", i, j);
        if (i != 9) printf("%d %d\n", i + 1, 0); 
    }

    return 0;
}
