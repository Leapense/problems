#include <stdio.h>
#include <string.h>

#define MAX_Y 1000001
#define UNVISITED -1

static int remainders_seen[MAX_Y];

void solve(int x, int y) {
    memset(remainders_seen, UNVISITED, sizeof(remainders_seen));

    int position = 0;
    int remainder = x;

    while (1) {
        if (remainders_seen[remainder] != UNVISITED) {
            int non_recurring_len = remainders_seen[remainder];
            int recurring_len = position - non_recurring_len;
            printf("%d %d\n", non_recurring_len, recurring_len);
            return;
        }

        remainders_seen[remainder] = position;
        remainder = (remainder * 10) % y;
        position++;
        if (remainder == 0) {
            printf("%d 0\n", position);
            return;
        }
    }
}

int main() {
    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    int x, y;
    while (scanf("%d %d", &x, &y) == 2) {
        if (x == 0 && y == 0) break;
        solve(x, y);
    }

    return 0;
}