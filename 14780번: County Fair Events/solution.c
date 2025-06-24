#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long start_time;
    long long end_time;
} Event;

int compare_events(const void *a, const void *b) {
    Event *event_a = (Event *)a;
    Event *event_b = (Event *)b;
    if (event_a->end_time != event_b->end_time) {
        return event_a->end_time - event_b->end_time;
    }

    return event_a->start_time - event_b->start_time;
}

int max_events(Event *events, int n) {
    qsort(events, n, sizeof(Event), compare_events);

    int count = 0;
    long long last_end_time = -1;

    for (int i = 0; i < n; i++) 
    {
        if (events[i].start_time >= last_end_time) {
            count++;
            last_end_time = events[i].end_time;
        }
    }

    return count;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Event *events = malloc(n * sizeof(Event));
    if (events == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        long long t, l;
        scanf("%lld %lld", &t, &l);
        events[i].start_time = t;
        events[i].end_time = t + l;
    }

    printf("%d\n", max_events(events, n));

    free(events);
    return 0;
}