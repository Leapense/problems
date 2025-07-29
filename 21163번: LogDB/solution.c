#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int arity;
    char **args;
} Fact;

static bool isNameChar(int ch) {
    return isalnum(ch) || ch == '_';
}

static char *dupRange(const char *a, const char *b) {
    size_t n = (size_t)(b - a);
    char *s = malloc(n + 1);
    memcpy(s, a, n);
    s[n] = 0;
    return s;
}

static void skipWs(const char **p) {
    while (**p && isspace((unsigned char) **p)) (*p)++;
}

static Fact parseFact(const char **p) {
    skipWs(p);
    const char *s = *p;
    const char *ns = s;
    while (*s && isNameChar(*s)) s++;
    char *name = dupRange(ns, s);
    skipWs(&s);
    s++;
    skipWs(&s);
    char **args = NULL;
    int arity = 0;
    int cap = 0;
    while (1) {
        const char *as = s;
        while (*s && isNameChar(*s)) s++;
        char *arg = dupRange(as, s);
        if (arity == cap) {
            cap = cap ? cap * 2 : 4;
            args = realloc(args, (size_t)cap * sizeof *args);
        }
        args[arity++] = arg;
        skipWs(&s);
        if (*s == ',') {
            s++;
            skipWs(&s);
            continue;
        }

        if (*s == ')') {
            s++;
            break;
        }
    }
    *p = s;
    return (Fact){name, arity, args};
}

static bool equals(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}

static long long matchCount(const Fact *facts, size_t n, const Fact *q) {
    long long cnt = 0;
    for (size_t i = 0; i < n; i++) {
        const Fact *f = facts + i;
        if (!equals(f->name, q->name) || f->arity != q->arity) continue;
        const int m = f->arity;
        const char *vars[64];
        const char *vals[64];
        int vcnt = 0;
        bool ok = true;
        for (int k = 0; k < m && ok; k++) {
            const char *qa = q->args[k];
            const char *fa = f->args[k];
            if (qa[0] == '_') {
                if (qa[1] == 0) continue;
                int j = 0;
                for (; j < vcnt; j++) {
                    if (equals(vars[j], qa)) break;
                }
                if (j == vcnt) {
                    vars[vcnt] = qa;
                    vals[vcnt] = fa;
                    vcnt++;
                } else if (!equals(vals[j], fa)) ok = false;
            } else if (!equals(qa, fa)) ok = false;
        }

        if (ok) cnt++;
    }

    return cnt;
}

int main(void) {
    Fact *facts = NULL;
    size_t fcnt = 0, fcap = 0;
    char line[256];
    while (fgets(line, sizeof line, stdin)) {
        const char *t = line;
        bool blank = true;
        for (const char *c = t; *c; c++) {
            if (!isspace((unsigned char)*c)) {
                blank = false;
                break;
            }
        }
        if (blank) break;
        while (1) {
            skipWs(&t);
            if (*t == 0 || *t == '\n') break;
            if (fcnt == fcap) {
                fcap = fcap ? fcap * 2 : 256;
                facts = realloc(facts, fcap * sizeof *facts);
            }
            facts[fcnt++] = parseFact(&t);
        }
    }

    while (fgets(line, sizeof line, stdin)) {
        const char *p = line;
        Fact q = parseFact(&p);
        printf("%lld\n", matchCount(facts, fcnt, &q));
        for (int i = 0; i < q.arity; i++) {
            free(q.args[i]);
        }

        free(q.args);
        free(q.name);
    }

    return 0;
}