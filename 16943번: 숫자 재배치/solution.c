#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static void swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}

static void reverse(char *s, int i, int j) {
    while (i < j) {
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
}

static bool prevPerm(char *s, int n) {
    int i = n - 2;
    while (i >= 0 && s[i] <= s[i + 1]) i--;
    if (i < 0) return false;
    int j = n - 1;
    while (s[j] >= s[i]) j--;
    swap(&s[i], &s[j]);
    reverse(s, i + 1, n - 1);
    return true;
}

static int cmpDesc(const void *p, const void *q) {
    return (*(char*)q) - (*(char*)p);
}

int main(void) {
    char a[20], b[20];
    if (scanf("%19s %19s", a, b) != 2) return 0;
    int n = strlen(a);
    int m = strlen(b);
    if (n > m) {
        printf("-1");
        return 0;
    }

    qsort(a, n, sizeof(char), cmpDesc);
    if (n < m) {
        if (a[0] == '0') printf("-1");
        else printf("%s", a);
        return 0;
    }

    if (a[0] != '0' && strcmp(a, b) < 0) {
        printf("%s", a);
        return 0;
    }

    while(prevPerm(a, n)) {
        if (a[0] == '0') continue;
        if (strcmp(a, b) < 0) {
            printf("%s", a);
            return 0;
        }
    }

    printf("-1");
    return 0;
}