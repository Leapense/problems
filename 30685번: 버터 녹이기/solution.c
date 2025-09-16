#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll x;
    ll s;
} Node;

int cmp_node(const void* a, const void* b) {
    const Node* A = (const Node*)a;
    const Node* B = (const Node*)b;
    if (A->x < B->x) return -1;
    if (A->x > B->x) return 1;
    return 0;
}

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Node* v = (Node*)malloc(sizeof(Node) * (size_t)N);
    if (!v) return 0;
    for (int i = 0; i < N; ++i) {
        ll x, h;
        scanf("%lld %lld", &x, &h);
        ll s = (h - 1) / 2;
        v[i].x = x;
        v[i].s = s;
    }

    qsort(v, (size_t)N, sizeof(Node), cmp_node);

    const ll INF = (ll)9e18;
    ll earliest = INF;

    for (int i = 0; i + 1 < N; ++i) {
        ll d = v[i+1].x - v[i].x;
        ll a = v[i].s < v[i+1].s ? v[i].s : v[i+1].s;
        ll b = v[i].s < v[i+1].s ? v[i+1].s : v[i].s;

        if (d > a + b) {
            continue;
        } else if (d <= 2 * a) {
            ll ti = (d + 1) / 2;
            if (ti < earliest) earliest = ti;
        } else {
            ll ti = d - a;
            if (ti < earliest) earliest = ti;
        }
    }

    if (earliest == INF) {
        puts("forever");
    } else {
        printf("%lld\n", earliest - 1);
    }

    free(v);
    return 0;
}