#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char buf[256];
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    size_t m = strlen(buf);
    char *s = malloc(m + 1);
    size_t si = 0;
    for (size_t i = 0; i < m; ++i) {
        if (buf[i] == '(' || buf[i] == ')') s[si++] = buf[i];
    }
    s[si] = '\0';
    int *stack = malloc((si + 5) * sizeof(int));
    int top = -1;
    long long total = 0;
    for (size_t i = 0; i < si; ++i) {
        char c = s[i];
        if (c == '(') {
            stack[++top] = 0;
        } else {
            int t = stack[top--];
            int h = (t == 0) ? 1 : t + 1;
            total += h;
            if (top >= 0) {
                if (stack[top] < h) stack[top] = h;
            }
        }
    }

    printf("%lld\n", total);
    free(s);
    free(stack);
    return 0;
}