// C23 표준 호환 버전
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int *a; size_t sz, cap;
} Vec; // for L

static void vec_init(Vec *v){ v->a=NULL; v->sz=0; v->cap=0; }
static void vec_reserve(Vec *v, size_t c){
    if (v->cap >= c) return;
    size_t nc = v->cap ? v->cap : 4;
    while (nc < c) nc <<= 1;
    v->a = (int*)realloc(v->a, nc * sizeof(int));
    v->cap = nc;
}
static void vec_push_back(Vec *v, int x){
    if (v->sz == v->cap) vec_reserve(v, v->sz+1);
    v->a[v->sz++] = x;
}
static int vec_pop_back(Vec *v){
    return v->a[--v->sz];
}
static void vec_clear(Vec *v){ v->sz = 0; }

typedef struct {
    int *a; size_t cap, sz, head; // circular buffer: [head .. head+sz)
} Deq; // for R

static void deq_init(Deq *d){ d->a=NULL; d->cap=0; d->sz=0; d->head=0; }
static void deq_reserve(Deq *d, size_t c){
    if (d->cap >= c) return;
    size_t nc = d->cap ? d->cap : 4;
    while (nc < c) nc <<= 1;
    int *na = (int*)malloc(nc * sizeof(int));
    for (size_t i=0;i<d->sz;i++){
        na[i] = d->a[(d->head + i) % d->cap];
    }
    free(d->a);
    d->a = na;
    d->cap = nc;
    d->head = 0;
}
static void deq_push_back(Deq *d, int x){
    if (d->sz == d->cap) deq_reserve(d, d->sz+1);
    size_t idx = (d->head + d->sz) % d->cap;
    d->a[idx] = x;
    d->sz++;
}
static void deq_push_front(Deq *d, int x){
    if (d->sz == d->cap) deq_reserve(d, d->sz+1);
    d->head = (d->head + d->cap - 1) % d->cap;
    d->a[d->head] = x;
    d->sz++;
}
static int deq_pop_front(Deq *d){
    int x = d->a[d->head];
    d->head = (d->head + 1) % d->cap;
    d->sz--;
    return x;
}
static void deq_clear(Deq *d){ d->sz=0; d->head=0; }

static Vec L;
static Deq R;
static long long sumL, sumR;

static void rebalance(void) {
    long long N = (long long)L.sz + (long long)R.sz;
    long long wantL = N / 2;
    long long wantR = N - wantL;
    while ((long long)R.sz > wantR) {
        int v = deq_pop_front(&R);
        sumR -= v;
        vec_push_back(&L, v);
        sumL += v;
    }
    while ((long long)R.sz < wantR) {
        int v = vec_pop_back(&L);
        sumL -= v;
        deq_push_front(&R, v);
        sumR += v;
    }
}

static void delete_front_half(void) {
    printf("%lld\n", sumL);
    sumL = 0;
    vec_clear(&L);
    long long M = (long long)R.sz;
    long long needL = M / 2;
    while ((long long)L.sz < needL) {
        int v = deq_pop_front(&R);
        sumR -= v;
        vec_push_back(&L, v);
        sumL += v;
    }
}

static void delete_back_half(void) {
    printf("%lld\n", sumR);
    sumR = 0;
    deq_clear(&R);
    long long M = (long long)L.sz;
    long long needR = M - (M/2);
    while ((long long)R.sz < needR) {
        int v = vec_pop_back(&L);
        sumL -= v;
        deq_push_front(&R, v);
        sumR += v;
    }
}

int main(void){
    int Q;
    if (scanf("%d", &Q) != 1) return 0;

    vec_init(&L);
    deq_init(&R);
    sumL = sumR = 0;

    for (int i=0;i<Q;i++){
        int t; scanf("%d", &t);
        if (t == 1){
            int x; scanf("%d", &x);
            deq_push_back(&R, x);
            sumR += x;
            rebalance();
        }else{
            if (sumL <= sumR) delete_front_half();
            else delete_back_half();
        }
    }

    // 최종 배열 출력: L 이어서 R
    bool first = true;
    for (size_t i=0;i<L.sz;i++){
        if (!first) printf(" ");
        printf("%d", L.a[i]);
        first = false;
    }
    for (size_t i=0;i<R.sz;i++){
        int v = R.a[(R.head + i) % R.cap];
        if (!first) printf(" ");
        printf("%d", v);
        first = false;
    }
    printf("\n");

    free(L.a); free(R.a);
    return 0;
}
