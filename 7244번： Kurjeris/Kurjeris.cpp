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

struct Order {
    int t;
    int v;
    int z1;
    int z2;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int M;
    cin >> M;

    vector<Order> orders(M);

    for (int i = 0; i < M; ++i) {
        cin >> orders[i].t >> orders[i].v >> orders[i].z1 >> orders[i].z2;
    }

    long long courier1_available = 0, courier2_available = 0;
    long long earnings1 = 0, earnings2 = 0;

    for (int i = 0; i < M; ++i) {
        Order current = orders[i];
        int t_i = current.t;
        int v_i = current.v;
        int z1_i = current.z1;
        int z2_i = current.z2;

        bool courier1_free = (courier1_available <= t_i);
        bool courier2_free = (courier2_available <= t_i);

        if (courier1_free and courier2_free) {
            if (z1_i < z2_i) {
                courier1_available = t_i + z1_i;
                earnings1 += v_i;
            } else if (z2_i < z1_i) {
                courier2_available = t_i + z2_i;
                earnings2 += v_i;
            } else {
                courier1_available = t_i + z1_i;
                earnings1 += v_i;
            }
        } else if (courier1_free) {
            courier1_available = t_i + z1_i;
            earnings1 += v_i;
        } else if(courier2_free) {
            courier2_available = t_i + z2_i;
            earnings2 += v_i;
        }
    }

    cout << earnings1 << " " << earnings2;

    return 0;
}