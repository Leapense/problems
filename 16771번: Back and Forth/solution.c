#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool seen[2001];
int c1[101];
int c2[101];

void dfs(int step, int milk) {
    if (step == 5) {
        seen[milk] = true;
        return;
    }

    if (step == 1 || step == 3) {
        for (int s = 1; s <= 100; ++s) {
            if (c1[s] > 0) {
                c1[s]--;
                c2[s]++;
                dfs(step + 1, milk - s);
                c1[s]++;
                c2[s]--;
            }
        }
    } else {
        for (int s = 1; s <= 100; ++s) {
            if (c2[s] > 0) {
                c2[s]--;
                c1[s]++;
                dfs(step + 1, milk + s);
                c2[s]++;
                c1[s]--;
            }
        }
    }
}

int main(void) {
    for (int i = 0; i <= 100; ++i) {
        c1[i] = 0;
        c2[i] = 0;
    }
    for (int i = 0; i < 10; ++i) {
        int x;
        scanf("%d", &x);
        c1[x]++;
    }
    for (int i = 0; i < 10; ++i) {
        int x;
        scanf("%d", &x);
        c2[x]++;
    }

    dfs(1, 1000);
    int count = 0;
    for (int i = 0; i <= 2000; ++i) {
        if (seen[i]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}