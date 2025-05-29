#include <stdio.h>
#include <stdlib.h> // For qsort, malloc, free
#include <string.h> // For memset (optional, but good practice for structs)

typedef struct {
    int temp;
    int delta_milk;
} EventC;

// qsort 비교 함수
// "compare_events_c"는 "static" 으로 선언되어야 함.
static int compare_events_c(const void* p1, const void* p2)
{
    // void 포인터를 실제 타입으로 캐스팅하기 전에 null인지 확인하십시오.
    // (qsort는 null 포인터를 전달하지 않는다고 가정합니다.)
    const EventC* ev1 = (const EventC*)p1;
    const EventC* ev2 = (const EventC*)p2;

    if (ev1 -> temp < ev2 -> temp) {
        return -1;
    }
    if (ev1 -> temp > ev2 -> temp) {
        return 1;
    }

    // 온도가 같을 경우, delta_milk 순서는 최종 합계에 영향을 주지 않음.
    // "0"을 반환하기 전에 "ev1->delta_milk"와 "ev2->delta_milk"를 비교하는 것을 고려함.
    return 0;
}

// 매개 변수 argc, argv를 사용하지 않는 경우 제거하거나 주석 처리
int main(void)
{
    int n, x, y, z;
    if (scanf("%d %d %d %d", &n, &x, &y, &z) != 4) {
        return 1; // 입력 오류 처리
    }

    EventC* events = (EventC*)malloc(sizeof(EventC) * (size_t)n * 2);
    if (events == NULL && n > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // 메모리 할당 실패
    }

    int event_count = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        if (scanf("%d %d", &a, &b) != 2) {
            if (events != NULL) free(events);
            return 1; // 입력 오류 처리
        }

        events[event_count].temp = a;
        events[event_count].delta_milk = y - x;
        event_count++;

        events[event_count].temp = b + 1;
        events[event_count].delta_milk = z - y;
        event_count++;
    }

    if (n > 0) {
        qsort(events, (size_t)event_count, sizeof(EventC), compare_events_c);
    }

    long long current_milk = (long long)n * x;
    long long max_milk = current_milk;

    int i = 0;
    while (i < event_count) {
        int current_event_temp = events[i].temp;
        int j = i;

        while (j < event_count && events[j].temp == current_event_temp) {
            current_milk += events[j].delta_milk;
            j++;
        }
        if (current_milk > max_milk) {
            max_milk = current_milk;
        }

        i = j;
    }

    printf("%lld\n", max_milk);

    if (events != NULL) free(events);

    return 0;
}