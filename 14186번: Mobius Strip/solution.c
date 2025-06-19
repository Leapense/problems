#include <stdio.h>

int main(void)
{
    while (1) {
        int a, b;
        if (scanf("%d %d", &a, &b) != 2) return 0;
        if (a < 0 && b < 0) break;

        int oddA = 0, oddB = 0, t;
        for (int i = 0; i < a; i++) {
            scanf("%d", &t);
            if (t & 1) {
                oddA++;
            }
        }

        for (int i = 0; i < b; i++) {
            scanf("%d", &t);
            if (t & 1) {
                oddB++;
            }
        }

        putchar((oddA == oddB) ? 'Y' : 'N');
        putchar('\n');
    }

    return 0;
}
