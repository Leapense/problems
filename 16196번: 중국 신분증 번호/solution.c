#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int cmp_u32(const void *a, const void *b) {
    uint32_t x = *(const uint32_t *)a;
    uint32_t y = *(const uint32_t *)b;
    return x < y ? -1 : (x > y);
}

static int is_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main(void) {
    char id[20];
    if (scanf("%18s", id) != 1) return 0;
    int n;
    scanf("%d", &n);
    uint32_t *regions = malloc(sizeof *regions * n);
    for (int i = 0; i < n; ++i) {
        char buf[8];
        scanf("%6s", buf);
        regions[i] = (uint32_t)strtoul(buf, NULL, 10);
    }
    qsort(regions, n, sizeof *regions, cmp_u32);

    for (int i = 0; i < 17; ++i) if (id[i] < '0' || id[i] > '9') { puts("I"); return 0; }
    if (!((id[17] >= '0' && id[17] <= '9') || id[17] == 'X')) { puts("I"); return 0; }

    char region_buf[7];
    memcpy(region_buf, id, 6);
    region_buf[6] = 0;
    uint32_t region_val = (uint32_t)strtoul(region_buf, NULL, 10);
    if (!bsearch(&region_val, regions, n, sizeof *regions, cmp_u32)) { puts("I"); return 0; }

    int year = (id[6]-'0')*1000 + (id[7]-'0')*100 + (id[8]-'0')*10 + (id[9]-'0');
    int month = (id[10]-'0')*10 + (id[11]-'0');
    int day = (id[12]-'0')*10 + (id[13]-'0');
    int dim[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_leap(year)) dim[1] = 29;
    int date_ok = year >= 1900 && year <= 2011 && month >= 1 && month <= 12 && day >= 1 && day <= dim[month-1];
    if (!(date_ok && (year < 2011 || (month < 12 || (month == 12 && day <= 31))))) { puts("I"); return 0; }

    if (id[14]=='0' && id[15]=='0' && id[16]=='0') { puts("I"); return 0; }
    int gender = (id[16]-'0') & 1;

    static const int w[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int sum = 0;
    for (int i = 0; i < 17; ++i) sum = (sum + (id[i]-'0') * w[i]) % 11;
    int x = (1 - sum + 11) % 11;
    char expect = x == 10 ? 'X' : (char)('0' + x);
    if (expect != id[17]) { puts("I"); return 0; }

    puts(gender ? "M" : "F");
    free(regions);
    return 0;
}