#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static long double phi_cdf(long double x) {
    return 0.5L * (1.0L + erf(x / M_SQRT2));
}

int main(void) {
    const int T = 100;
    const int n = 5000;
    const int B = 300;
    const long double mu = 0.5L;
    const long double var = 0.1L;
    const long double sigma = sqrtl(var);
    const long double inv_sigma = 1.0L / sigma;
    const long double Z = phi_cdf((1.0L - mu) * inv_sigma) - phi_cdf((0.0L - mu) * inv_sigma);
    const long double binw = 1.0L / (long double)B;

    for (int tc = 0; tc < T; ++tc) {
        long double *a = (long double*)malloc(sizeof(long double) * B);
        long double *b = (long double*)malloc(sizeof(long double) * B);
        long double *EcA = (long double*)malloc(sizeof(long double) * B);
        long double *EcB = (long double*)malloc(sizeof(long double) * B);
        long double *O = (long double*)malloc(sizeof(long double) * B);
        if (!a || !b || !EcA || !EcB || !O) return 0;

        for (int i = 0; i < B; ++i) {
            a[i] = (long double)i * binw;
            b[i] = (long double)(i + 1) * binw;
            O[i] = 0.0L;
        }

        for (int i = 0; i < n; ++i) {
            long double x;
            if (scanf("%Lf", &x) != 1) return 0;
            if (x < 0.0L) x = 0.0L;
            if (x > 1.0L) x = 1.0L;
            int idx = (int)floorl(x * (long double)B);
            if (idx == B) idx = B - 1;
            O[idx] += 1.0L;
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

        long double GA = 0.0L, GB = 0.0L;
        for (int i = 0; i < B; ++i) {
            long double oi = O[i];
            long double ea = EcA[i];
            long double eb = EcB[i];
            if (oi > 0.0L && ea > 0.0L) GA += 2.0L * oi * logl(oi / ea);
            if (oi > 0.0L && eb > 0.0L) GB += 2.0L * oi * logl(oi / eb);
        }

        char ans = (GB < GA) ? 'B' : 'A';
        printf("%c\n", ans);

        free(a);
        free(b);
        free(EcA);
        free(EcB);
        free(O);
    }
    return 0;
}