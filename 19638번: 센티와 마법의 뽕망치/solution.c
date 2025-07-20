#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int N, T;
    int64_t Hc;
    if (scanf("%d %" SCNd64 " %d", &N, &Hc, &T) != 3) return 0;
    int cap = N + T + 1;
    int64_t *heap = (int64_t *)malloc(sizeof(int64_t) * cap);
    int heapSize = 0;
    for (int i = 0; i < N; i++) {
        scanf("%" SCNd64, &heap[++heapSize]);
    }

    for (int i = heapSize / 2; i >= 1; i--) {
        int cur = i;
        for(;;) {
            int largest = cur;
            int l = cur * 2, r = l + 1;
            if (l <= heapSize && heap[l] > heap[largest]) largest = l;
            if (r <= heapSize && heap[r] > heap[largest]) largest = r;
            if (largest == cur) break;
            int64_t tmp = heap[cur];
            heap[cur] = heap[largest];
            heap[largest] = tmp;
            cur = largest;
        }
    }
    int used = 0;
    for (int i = 0; i < T; i++) {
        if (heapSize == 0) break;
        int64_t top = heap[1];
        if (top < Hc) {
            printf("YES\n%d\n", used);
            free(heap);
            return 0;
        }
        if (top == 1) break;
        int64_t nh = top / 2;
        heap[1] = nh;
        int cur = 1;
        for (;;) {
            int largest = cur;
            int l = cur * 2, r = l + 1;
            if (l <= heapSize && heap[l] > heap[largest]) largest = l;
            if (r <= heapSize && heap[r] > heap[largest]) largest = r;
            if (largest == cur) break;
            int64_t tmp = heap[cur];
            heap[cur] = heap[largest];
            heap[largest] = tmp;
            cur = largest;
        }
        used++;
    }

    if (heapSize > 0 && heap[1] < Hc) {
        printf("YES\n%d\n", used);
    } else {
        int64_t mx = (heapSize > 0) ? heap[1] : 0;
        printf("NO\n%" PRId64 "\n", mx);
    }

    free(heap);
    return 0;
}