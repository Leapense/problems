#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

typedef struct Node {
    i64 key;
    int cnt;
    struct Node *next;
} Node;

static Node *new_node(i64 key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->cnt = 1;
    p->next = NULL;
    return p;
}

static void inc(Node **tbl, size_t mask, i64 key) {
    size_t idx = (size_t)(key & (i64)mask);
    Node *cur = tbl[idx];
    while (cur) {
        if (cur->key == key) {
            cur->cnt++;
            return;
        }
        cur = cur->next;
    }
    Node *fresh = new_node(key);
    fresh->next = tbl[idx];
    tbl[idx] = fresh;
}

static int get(Node **tbl, size_t mask, i64 key) {
    size_t idx = (size_t)(key & (i64)mask);
    Node *cur = tbl[idx];
    while (cur) {
        if (cur->key == key) return cur->cnt;
        cur = cur->next;
    }
    return 0;
}

static void free_tbl(Node **tbl, size_t cap) {
    for (size_t i = 0; i < cap; ++i) {
        Node *cur = tbl[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        i64 a[2000];
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

        const size_t cap = 4096;
        const size_t mask = cap - 1;
        Node *tbl[4096] = {0};

        i64 ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                i64 want = 2 * a[j] - a[k];
                ans += get(tbl, mask, want);
            }
            inc(tbl, mask, a[j]);
        }
        printf("%lld\n", ans);
        free_tbl(tbl, cap);
    }

    return 0;
}