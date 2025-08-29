#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int cd = 1; cd <= n; ++cd) {
        int t, k;
        scanf("%d %d", &t, &k);
        int *len = (int*)malloc(sizeof(int) * t);
        for (int i = 0; i < t; ++i) scanf("%d", &len[i]);
        int d;
        scanf("%d", &d);
        printf("CD #%d:\n", cd);
        for (int day = 0; day < d; ++day) {
            int s;
            scanf("%d", &s);

            int *seg = (int*)malloc(sizeof(int) * s);
            for (int i = 0; i < s; ++i) scanf("%d", &seg[i]);

            long long total_k = 0;
            int current_track = 1;
            int offset = 0;
            for (int i = 0; i < s; ++i) {
                int L = seg[i];
                int seg_index = i + 1;
                if (seg_index % 2 == 1) {
                    current_track = k;
                    offset = 0;
                    total_k += L;
                    int lk = len[k - 1];
                    int off = L % lk;
                    if (off == 0) {
                        current_track = (k < t) ? k + 1 : 1;
                        offset = 0;
                    } else {
                        current_track = k;
                        offset = off;
                    }
                } else {
                    int remaining = L;
                    while (remaining > 0) {
                        int curr_len = len[current_track - 1];
                        int rem_in_track = curr_len - offset;
                        int take = remaining < rem_in_track ? remaining : rem_in_track;
                        if (current_track == k) total_k += take;
                        remaining -= take;
                        offset += take;
                        if (offset == curr_len) {
                            offset = 0;
                            current_track = (current_track < t) ? current_track + 1 : 1;
                        }
                    }
                }
            }

            printf("%lld\n", total_k);
            free(seg);
        }
        if (cd != n) printf("\n");
        else printf("");
        free(len);
    }

    return 0;
}