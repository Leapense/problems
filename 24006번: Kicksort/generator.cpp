#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick() {}
    Fenwick(int n): n(n), f(n + 1, 0) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    int kth(int k) const {
        int idx = 0;
        int bit = 1;
        while ((bit << 1) <= n) bit <<= 1;
        for (int b = bit; b > 0; b >>= 1) {
            int nxt = idx + b;
            if (nxt <= n && f[nxt] < k) {
                k -= f[nxt];
                idx = nxt;
            }
        }

        return idx + 1;
    }
};

bool all_pivots_worst(int n, const vector<int>& arr1) {
    Fenwick tree(n);
    for (int i = 1; i <= n; ++i) tree.add(i, 1);
    vector<char> removed(n + 2, false);    
    int lo = 1, hi = n, length = n;
    while (length >= 2) {
        int k = (length + 1) / 2;
        int pos = tree.kth(k);
        int val = arr1[pos];
        if (val != lo && val != hi) return false;
        tree.add(pos, -1);
        removed[val] = true;
        while (lo <= n && removed[lo]) ++lo;
        while (hi >= 1 && removed[hi]) --hi;
        --length;
    }

    return true;
}

vector<int> buildYesPermutation(int n) {
    vector<int> ans(n + 1, -1);
    Fenwick tree(n);
    for (int i = 1; i <= n; ++i) tree.add(i, 1);

    int lo = 1, hi = n, length = n;
    while (length > 0) {
        int k = (length + 1) / 2;
        int pos = tree.kth(k);
        int chooseHi = (lo == hi) ? 0 : rnd.next(2);
        int val = chooseHi ? hi : lo;
        ans[pos] = val;
        tree.add(pos, -1);
        if (val == lo) ++lo; else --hi;
        --length;
    }

    ensuref(all_pivots_worst(n, ans), "Internal error: built YES permutation failed check");
    return ans;
}

vector<int> randomPermutation(int n) {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = n; i >= 2; --i) swap(a[i], a[rnd.next(i) + 1]);
    return a;
}

vector<int> buildNoFailFirstStep(int n) {
    vector<int> a = buildYesPermutation(n);
    if (n >= 3) {
        int midPos = (n + 1) / 2;
        int targetVal = 2;
        if (targetVal > n - 1) targetVal = n - 1;
        int idx = -1;
        for (int i = 1; i <= n; ++i) if (a[i] == targetVal) {idx = i; break;}
        if (idx == -1) {
            for (int v = 2; v <= n - 1 && idx == -1; ++v) {
                for (int i = 1; i <= n; ++i) if (a[i] == v) {idx = i; break;}
            }
        }

        if (idx != -1 && idx != midPos) swap(a[idx], a[midPos]);
    }

    if (n >= 3 && all_pivots_worst(n, a)) {
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i) a[i] = i;
        ensure(!all_pivots_worst(n, a));
    }

    return a;
}

vector<int> ascending(int n) {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = i;
    return a;
}

vector<int> descending(int n) {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = n - i + 1;
    return a;
}

struct Test {
    int n;
    vector<int> a;
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = (argc >= 2 ? string(argv[1]) : string("sub2"));

    vector<Test> tests;

    if (mode == "sub1") {
        for (int n = 2; n <= 4; ++n) {
            vector<int> a(n);
            iota(a.begin(), a.end(), 1);
            do {
                vector<int> b(n + 1);
                for (int i = 1; i <= n; ++i) b[i] = a[i - 1];
                tests.push_back({n, b});
            } while (next_permutation(a.begin(), a.end()));
        }
    } else {
        const int Ttarget = 100;
        {
            tests.push_back({2, ascending(2)});
            tests.push_back({2, descending(2)});
        }

        for (int n = 3; n <= 10; ++n) {
            tests.push_back({n, ascending(n)});
            tests.push_back({n, descending(n)});
        }

        {
            int n1 = 9999, n2 = 10000;
            tests.push_back({n1, ascending(n1)});
            tests.push_back({n1, descending(n1)});
            tests.push_back({n2, ascending(n2)});
            tests.push_back({n2, descending(n2)});
        }

        auto addYes = [&](int n) {
            tests.push_back({n, buildYesPermutation(n)});
        };
        for (int i = 0; i < 10; ++i) addYes(rnd.wnext(50, 5) + 2);
        for (int i = 0; i < 10; ++i) addYes(rnd.next(100, 1000));
        for (int i = 0; i < 8; ++i) addYes(rnd.next(8000, 10000));

        auto addRandom = [&](int n) {
            tests.push_back({n, randomPermutation(n)});
        };
        for (int i = 0; i < 8; ++i) addRandom(rnd.next(2, 30));
        for (int i = 0; i < 10; ++i) addRandom(rnd.next(100, 2000));
        for (int i = 0; i < 7; ++i) addRandom(rnd.next(5000, 10000));

        auto addNo = [&](int n) {
            tests.push_back({n, buildNoFailFirstStep(n)});
        };
        for (int i = 0; i < 10; ++i) addNo(rnd.next(3, 50));
        for (int i = 0; i < 5; ++i) addNo(rnd.next(100, 2000));
        for (int i = 0; i < 4; ++i) addNo(rnd.next(5000, 10000));

        if ((int)tests.size() > Ttarget) {
            for (int i = (int)tests.size() - 1; i > 0; --i) {
                int j = rnd.next(i + 1);
                swap(tests[i], tests[j]);
            }
            tests.resize(Ttarget);
        }

        while ((int)tests.size() < Ttarget) {
            int n = rnd.next(2, 10000);
            if (rnd.next(2) == 0) tests.push_back({n, buildYesPermutation(n)});
            else tests.push_back({n, randomPermutation(n)});
        }

        for (int i = (int)tests.size() - 1; i > 0; --i) {
            int j = rnd.next(i + 1);
            swap(tests[i], tests[j]);
        }

        for (const auto& tc : tests) {
            int n = tc.n;
            ensuref(n >= 2 && n <= 10000, "n out of range");
            vector<int> cnt(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                int v = tc.a[i];
                ensuref(1 <= v && v <= n, "value out of range");
                cnt[v]++;
            }
            for (int v = 1; v <= n; ++v) ensuref(cnt[v] == 1, "not a permutation");
        }
    }

    cout << (int) tests.size() << '\n';
    for (const auto& tc : tests) {
        cout << tc.n << "\n";
        for (int i = 1; i <= tc.n; ++i) {
            if (i > 1) cout << ' ';
            cout << tc.a[i];
        }

        cout << '\n';
    }

    return 0;
}