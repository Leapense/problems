// C23 implementation
#include <stdio.h>

int main(void) {
    long long x1a, y1a, x2a, y2a;
    long long x1b, y1b, x2b, y2b;
    if (scanf("%lld %lld %lld %lld", &x1a, &y1a, &x2a, &y2a) != 4) return 0;
    if (scanf("%lld %lld %lld %lld", &x1b, &y1b, &x2b, &y2b) != 4) return 0;
    long long ovX = (x2a < x2b ? x2a : x2b) - (x1a > x1b ? x1a : x1b);
    long long ovY = (y2a < y2b ? y2a : y2b) - (y1a > y1b ? y1a : y1b);
    if (ovX < 0 || ovY < 0) {
        puts("NULL");
    } else if (ovX == 0 && ovY == 0) {
        puts("POINT");
    } else if (ovX == 0 || ovY == 0) {
        puts("LINE");
    } else {
        puts("FACE");
    }
    return 0;
}