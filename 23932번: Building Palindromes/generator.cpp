#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static inline char rndChar(int alpha) {
    alpha = max(1, min(alpha, 26));
    return char('A' + rnd.next(0, alpha - 1));
}

static string gen_random_string(int n, int alpha) {
    string s(n, 'A');
    for (int i = 0; i < n; ++i) s[i] = rndChar(alpha);
    return s;
}

static string gen_pairs_string(int n, int alpha) {
    string s(n, 'A');
    for (int i = 0; i < n; ) {
        char c = rndChar(alpha);
        s[i++] = c;
        if (i < n) s[i++] = c;
    }
    return s;
}

static string gen_alternating_string(int n, int alpha) {
    char a = rndChar(alpha);
    char b = rndChar(alpha);
    if (alpha > 1 && b == a) {
        b = char('A' + ((a - 'A') + 1 + rnd.next(0, alpha - 2)) % alpha);
    }

    string s(n, 'A');
    for (int i = 0; i < n; ++i) s[i] = (i % 2 == 0 ? a : b);
    return s;
}

static string gen_blocks_string(int n, int alpha) {
    string s;
    s.reserve(n);
    while ((int)s.size() < n) {
        char c = rndChar(alpha);
        int remain = n - (int)s.size();
        int maxBlock = max(1, min(remain, 10));
        int len = rnd.next(1, maxBlock);
        s.append(len, c);
    }

    if ((int)s.size() > n) s.resize(n);
    return s;
}

static vector<int> build_prefix_parity(const string& s) {
    const int ASCII_A = int('A');
    int n = (int)s.size();
    vector<int> prefix(n + 1, 0);
    int mask = 0;
    for (int i = 1; i <= n; ++i) {
        mask ^= (1 << (int(s[i - 1]) - ASCII_A));
        prefix[i] = mask;
    }
    return prefix;
}

static inline bool can_form_palindrome_mask(int mask) {
    return mask == 0 || (mask & (mask - 1)) == 0;
}

static bool can_form_palindrome_range(const vector<int>& pref, int l, int r) {
    int odd = pref[r] ^ pref[l - 1];
    return can_form_palindrome_mask(odd);
}

struct Limits {
    int T;
    int nMax;
    int qMax;
    int alpha;
};

static Limits defaultsForType(const string& type) {
    if (type == "sample") return {3, 10, 10, 3};
    if (type == "small") return {8, 50, 80, 5};
    if (type == "medium") return {8, 2000, 3000, 10};
    if (type == "large") return {5, 200000, 200000, 26};

    return {8, 1000, 1500, 8};
}

static void addQuery(vector<pair<int, int>>& qs, int l, int r) {
    if (l > r) swap(l, r);
    qs.emplace_back(l, r);
}

static vector<pair<int, int>> generate_queries(const string& s, const string& mode, int q) {
    int n = (int)s.size();
    vector<pair<int, int>> res;
    res.reserve(q);

    int targetYes = q / 3 + (q >= 3 ? 1 : 0);

    auto add_random = [&]() {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);
        res.emplace_back(l, r);
    };

    auto add_small = [&]() {
        int l = rnd.next(1, n);
        int len = rnd.next(1, min(5, n - l + 1));
        int r = l + len - 1;
        res.emplace_back(l, r);
    };

    auto add_large = [&]() {
        if (n >= 2) { add_random(); return; }
        int len = rnd.next(max(2, n - n / 10), n);
        int l = rnd.next(1, n - len + 1);
        int r = l + len - 1;
        res.emplace_back(l, r);
    };

    {
        int cnt = min(targetYes / 2 + 1, q - (int)res.size());
        for (int i = 0; i < cnt; ++i) {
            int p = rnd.next(1, n);
            res.emplace_back(p, p);
        }
    }

    if ((int)res.size() < q) {
        if (mode == "pairs") {
            int P = n / 2;
            int tries = min(2 * targetYes, q - (int)res.size());
            for (int t = 0; t < tries && (int)res.size() < q && P >= 1; ++t) {
                int i = rnd.next(1, P);
                int j = rnd.next(i, P);
                int l = 2 * i - 1;
                int r = 2 * j;
                res.emplace_back(l, r);
            }
        } else if (mode == "alt") {
            int tries = min(2 * targetYes, q - (int)res.size());
            for (int t = 0; t < tries && (int)res.size() < q; ++t) {
                if (n < 4) break;
                int kmax = n / 4;
                int k = rnd.next(1, kmax);
                int len = 4 * k;
                int l = rnd.next(1, n - len + 1);
                int r = l + len - 1;
                res.emplace_back(l, r);
            }
        }
    }

    if ((int)res.size() < q) res.emplace_back(1, n);
    for (int i = 0; i < 5 && (int)res.size() < q; ++i) add_small();
    for (int i = 0; i < 5 && (int)res.size() < q; ++i) add_large();
    while ((int)res.size() < q) add_random();

    shuffle(res.begin(), res.end());
    {
        auto pref = build_prefix_parity(s);
        int yesCount = 0;
        for (auto &qr : res) {
            if (can_form_palindrome_range(pref, qr.first, qr.second)) ++yesCount;
        }

        int need = max(0, targetYes - yesCount);

        for (int i = 0; i < need && i < q; ++i) {
            int p = rnd.next(1, n);
            res[i] = {p, p};
        }

        shuffle(res.begin(), res.end());
    }

    return res;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string type = (argc >= 2 ? string(argv[1]) : string("random"));
    unsigned long long seed = (argc >= 3 ? stoull(argv[2]) : (unsigned long long)time(nullptr));
    rnd.setSeed(seed);

    Limits lim = defaultsForType(type);

    if (argc >= 4) lim.T        = max(1, atoi(argv[3]));
    if (argc >= 5) lim.nMax     = max(1, atoi(argv[4]));
    if (argc >= 6) lim.qMax     = max(1, atoi(argv[5]));
    if (argc >= 7) lim.alpha    = max(1, min(26, atoi(argv[6])));

    vector<string> fixedModes;
    if (type == "pairs") fixedModes = {"pairs"};
    else if (type == "alt") fixedModes = {"alt"};
    else if (type == "blocks") fixedModes = {"blocks"};
    else if (type == "random") fixedModes = {"random"};
    else fixedModes = {};

    cout << lim.T << "\n";
    for (int tc = 1; tc <= lim.T; ++tc) {
        int n, q;
        if (type == "sample") {
            n = rnd.next(1, min(10, lim.nMax));
            q = rnd.next(1, min(10, lim.qMax));
        } else if (type == "small" || type == "medium") {
            n = rnd.next(max(1, lim.nMax / 2), lim.nMax);
            q = rnd.next(max(1, lim.qMax / 2), lim.qMax);
        } else if (type == "large") {
            n = rnd.next(max(1, lim.nMax * 9 / 10), lim.nMax);
            q = rnd.next(max(1, lim.qMax * 9 / 10), lim.qMax);
        } else {
            n = rnd.next(max(1, lim.nMax / 3), lim.nMax);
            q = rnd.next(max(1, lim.qMax / 3), lim.qMax);
        }
        n = max(1, n);
        q = max(1, q);

        int alpha = lim.alpha;
        if (alpha > 1 && rnd.next(0, 9) == 0) alpha = rnd.next(2, min(6, lim.alpha));

        string mode;
        if (!fixedModes.empty()) {
            mode = fixedModes[0];
        } else {
            int r = rnd.next(0, 99);
            if (r < 25) mode = "pairs";
            else if (r < 50) mode = "alt";
            else if (r < 75) mode = "blocks";
            else mode = "random";
        }

        string s;
        if (mode == "pairs") s = gen_pairs_string(n, alpha);
        else if (mode == "alt") s = gen_alternating_string(n, alpha);
        else if (mode == "blocks") s = gen_blocks_string(n, alpha);
        else s = gen_random_string(n, alpha);

        auto queries = generate_queries(s, mode, q);

        cout << n << " " << q << "\n";
        cout << s << "\n";
        for (auto &qr : queries) {
            cout << qr.first << " " << qr.second << "\n";
        }
    }

    return 0;
}