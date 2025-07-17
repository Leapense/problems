#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char name[13];
} Name;

typedef struct {
    size_t id;
    uint8_t used;
} HashEntry;

static uint64_t djb2(const char *s) {
    uint64_t h = 5381;
    while (*s) h = ((h << 5) + h) ^ (uint8_t)*s++;
    return h;
}

int main(void) {
    size_t n, k;
    if (scanf("%zu %zu", &n, &k) != 2) return 0;

    char ***prefStr = (char***)malloc(n * sizeof *prefStr);
    size_t *qArr = (size_t*)malloc(n * sizeof *qArr);
    for (size_t i = 0; i < n; ++i) {
        size_t q;
        scanf("%zu", &q);
        qArr[i] = q;
        prefStr[i] = (char **)malloc(q * sizeof **prefStr);
        for (size_t j = 0; j < q; ++j) {
            prefStr[i][j] = (char*)malloc(13);
            scanf("%12s", prefStr[i][j]);
        }
    }

    size_t p;
    scanf("%zu", &p);
    Name *rankNames = (Name *)malloc(p * sizeof *rankNames);
    for (size_t i = 0; i < p; ++i) scanf("%12s", rankNames[i].name);

    size_t cap = 1;
    while (cap < p * 2) cap <<= 1;
    HashEntry *ht = (HashEntry*)calloc(cap, sizeof *ht);

    for (size_t i = 0; i < p; ++i) {
        size_t idx = djb2(rankNames[i].name) & (cap - 1);
        while (ht[idx].used) idx = (idx + 1) & (cap - 1);
        ht[idx].id = i;
        ht[idx].used = 1;
    }

    size_t **pref = (size_t**)malloc(n * sizeof *pref);
    for (size_t i = 0; i < n; ++i) {
        pref[i] = (size_t*)malloc(qArr[i] * sizeof **pref);
        for (size_t j = 0; j < qArr[i]; ++j) {
            const char *s = prefStr[i][j];
            size_t idx = djb2(s) & (cap - 1);
            while (ht[idx].used && strcmp(rankNames[ht[idx].id].name, s) != 0)
                idx = (idx + 1) & (cap - 1);
            pref[i][j] = ht[idx].id;
            free(prefStr[i][j]);
        }
        free(prefStr[i]);
    }
    free(prefStr);

    char *taken = (char*)calloc(p, 1);
    size_t *prefPtr = (size_t*)calloc(n, sizeof *prefPtr);
    size_t rankPtr = 0;

    size_t **roster = (size_t**)malloc(n * sizeof *roster);
    for (size_t i = 0; i < n; ++i)
        roster[i] = (size_t*)malloc(k * sizeof **roster);

    for (size_t round = 0; round < k; ++round) {
        for (size_t owner = 0; owner < n; ++owner) {
            size_t pick;
            size_t pp = prefPtr[owner];
            while (pp < qArr[owner] && taken[pref[owner][pp]]) ++pp;
            if (pp < qArr[owner]) {
                pick = pref[owner][pp];
                prefPtr[owner] = pp + 1;
            } else {
                while (taken[rankPtr]) ++rankPtr;
                pick = rankPtr++;
            }
            taken[pick] = 1;
            roster[owner][round] = pick;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            printf("%s", rankNames[roster[i][j]].name);
            if (j + 1 < k) putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}