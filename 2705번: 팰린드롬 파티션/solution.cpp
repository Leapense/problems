#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    static const uint32_t BASE = 1000000000;
    vector<uint32_t> d;
    
    BigInt(uint64_t x = 0) {
        if (x == 0) return;
        while (x) {
            d.push_back(uint32_t(x % BASE));
            x /= BASE;
        }
    }
    
    BigInt& operator+=(BigInt const& o) {
        uint64_t carry = 0;
        size_t n = max(d.size(), o.d.size());
        if (d.size() < n) d.resize(n, 0);
        for (size_t i = 0; i < n; i++) {
            uint64_t sum = carry + d[i] + (i < o.d.size() ? o.d[i] : 0);
            d[i] = uint32_t(sum % BASE);
            carry = sum / BASE;
        }
        if (carry) d.push_back(uint32_t(carry));
        return *this;
    }
    
    friend BigInt operator+(BigInt a, BigInt const& b) {
        a += b;
        return a;
    }
    
    string toString() const {
        if (d.empty()) return "0";
        string s = to_string(d.back());
        char buf[16];
        for (int i = int(d.size()) - 2; i >= 0; --i) {
            snprintf(buf, sizeof(buf), "%09u", d[i]);
            s += buf;
        }
        
        return s;
    }
};

static vector<BigInt> dp;
static vector<BigInt> prefix;
static int computed_up_to = -1;

static void ensure_computed(int N) {
    if (N <= computed_up_to) return;
    if (computed_up_to < 0) {
        dp.assign(1, BigInt(1));
        prefix.assign(1, BigInt(1));
        computed_up_to = 0;
    }
    dp.resize(N+1);
    prefix.resize(N+1);
    for (int n = computed_up_to + 1; n <= N; ++n) {
        int half = (n - 1) / 2;
        BigInt val = prefix[half];
        if ((n & 1) == 0) {
            val += dp[n / 2];
        }
        
        dp[n] = val;
        prefix[n] = prefix[n-1] + dp[n];
    }
    
    computed_up_to = N;
}

string get_recursive_palindrome_partition_count(int N) {
    assert(N >= 0);
    ensure_computed(N);
    return dp[N].toString();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    
    vector<int> Q(T);
    int mx = 0;
    for (int i = 0; i < T; i++) {
        cin >> Q[i];
        mx = max(mx, Q[i]);
    }
    
    ensure_computed(mx);
    for (int x : Q) {
        cout << dp[x].toString() << "\n";
    }
    
    return 0;
}