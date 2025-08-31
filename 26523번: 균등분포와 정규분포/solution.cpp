#include <bits/stdc++.h>
using namespace std;

static long double phi_cdf(long double x) {
    return 0.5L * (1.0L + erf(x / M_SQRT2l));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int T = 100;
    const int n = 5000;
    const int B = 300;
    const long double mu = 0.5L;
    const long double var = 0.1L;
    const long double sigma = sqrtl(var);
    const long double inv_sigma = 1.0L / sigma;
    const long double Z = phi_cdf((1.0L - mu) * inv_sigma) - phi_cdf((0.0L - mu) * inv_sigma);
    const long double binw = 1.0L / (long double)B;

    cout.setf(std::ios::fixed);
    cout.precision(0);

    for (int tc = 0; tc < T; ++tc) {
        vector<long double> a(B), b(B);
        vector<long double> EcA(B), EcB(B);
        vector<long double> O(B, 0.0L);

        for (int i = 0; i < B; ++i) {
            a[i] = (long double)i * binw;
            b[i] = (long double)(i + 1) * binw;
        }

        for (int i = 0; i < n; ++i) {
            long double x;
            if (!(cin >> x)) return 0;
            if (x < 0.0L) x = 0.0L;
            if (x > 1.0L) x = 1.0L;
            int idx = (int)floorl(x * (long double)B);
            if (idx == B) idx = B - 1;
            ++O[idx];
        }

        for (int i = 0; i < B; ++i) {
            EcA[i] = (long double)n / (long double)B;
            long double Fa = phi_cdf((a[i] - mu) * inv_sigma);
            long double Fb = phi_cdf((b[i] - mu) * inv_sigma);
            long double p = (Fb - Fa) / Z;
            if (p < 0.0L) p = 0.0L;
            if (p > 1.0L) p = 1.0L;
            EcB[i] = (long double)n * p;
        }

        auto g_stat = [](const vector<long double>& O, const vector<long double>& E) {
            long double g = 0.0L;
            for (size_t i = 0; i < O.size(); ++i) {
                long double oi = O[i];
                long double ei = E[i];
                if (oi > 0.0L && ei > 0.0L) g += 2.0L * oi * logl(oi / ei);
            }
            return g;
        };

        long double GA = g_stat(O, EcA);
        long double GB = g_stat(O, EcB);

        char ans = (GB < GA) ? 'B' : 'A';
        cout << ans << '\n';
    }
    return 0;
}