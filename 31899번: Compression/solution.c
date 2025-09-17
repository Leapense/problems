#include <stdio.h>
#include <string.h>

int main(void)
{
    static char s[100005];
    if (scanf("%100004s", s) != 1) return 0;

    int n = (int)strlen(s);
    static char res[100005];
    int m = 0;

    for (int i = 0; i < n; ++i) {
        res[m++] = s[i];
        for (;;) {
            if (m >= 2 && res[m - 1] == res[m - 2]) {
                --m;
                continue;
            }
            if (m >= 4 && res[m - 4] == res[m - 2] && res[m - 3] == res[m - 1]) {
                m -= 2;
                continue;
            }
            break;
        }
    }
    res[m] = '\0';
    puts(res);
    return 0;
}