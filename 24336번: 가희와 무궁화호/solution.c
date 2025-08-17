#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STOPS 43
#define NAME_LEN 32
#define DAY_MINUTES 1440

typedef struct {
    char name[NAME_LEN];
    int arr_tod;
    int dep_tod;
    int arr_abs;
    int dep_abs;
} Stop;

typedef struct {
    const char* name;
    double dist;
} StationRef;

static const StationRef STATIONS[] = {
    {"Seoul", 0.0},
    {"Yeongdeungpo", 9.1},
    {"Anyang", 23.9},
    {"Suwon", 41.5},
    {"Osan", 56.5},
    {"Seojeongri", 66.5},
    {"Pyeongtaek", 75.0},
    {"Seonghwan", 84.4},
    {"Cheonan", 96.6},
    {"Sojeongni", 107.4},
    {"Jeonui", 114.9},
    {"Jochiwon", 129.3},
    {"Bugang", 139.8},
    {"Sintanjin", 151.9},
    {"Daejeon", 166.3},
    {"Okcheon", 182.5},
    {"Iwon", 190.8},
    {"Jitan", 196.4},
    {"Simcheon", 200.8},
    {"Gakgye", 204.6},
    {"Yeongdong", 211.6},
    {"Hwanggan", 226.2},
    {"Chupungyeong", 234.7},
    {"Gimcheon", 253.8},
    {"Gumi", 276.7},
    {"Sagok", 281.3},
    {"Yangmok", 289.5},
    {"Waegwan", 296.0},
    {"Sindong", 305.9},
    {"Daegu", 323.1},
    {"Dongdaegu", 326.3},
    {"Gyeongsan", 338.6},
    {"Namseonghyeon", 353.1},
    {"Cheongdo", 361.8},
    {"Sangdong", 372.2},
    {"Miryang", 381.6},
    {"Samnangjin", 394.1},
    {"Wondong", 403.2},
    {"Mulgeum", 412.4},
    {"Hwamyeong", 421.8},
    {"Gupo", 425.2},
    {"Sasang", 430.3},
    {"Busan", 441.7}
};

static int parse_time_tod(const char* s) {
    if (s[0] == '-' && s[1] == ':' && s[2] == '-') return -1;
    int hh = 0, mm = 0;
    if (sscanf(s, "%d:%d", &hh, &mm) != 2) return -1;
    return hh * 60 + mm;
}

static int compute_next_abs(int prev_abs, int next_tod) {
    if (next_tod < 0) return -1;
    if (prev_abs < 0) return next_tod;
    int prev_tod = prev_abs % DAY_MINUTES;
    int base = prev_abs - prev_tod;
    int candidate = base + next_tod;
    if (!(prev_tod < next_tod)) candidate += DAY_MINUTES;
    return candidate;
}

static double get_distance_by_name(const char* name) {
    size_t sz = sizeof(STATIONS) / sizeof(STATIONS[0]);
    for (size_t i = 0; i < sz; i++) {
        if (strcmp(STATIONS[i].name, name) == 0) return STATIONS[i].dist;
    }

    return 0.0;
}

static int find_stop_index(Stop* stops, int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stops[i].name, name) == 0) return i;
    }

    return -1;
}

int main(void) {
    int n = 0, q = 0;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    Stop stops[MAX_STOPS];
    for (int i = 0; i < n; i++) {
        char arr[8], dep[8];
        if (scanf("%31s %7s %7s", stops[i].name, arr, dep) != 3) return 0;
        stops[i].arr_tod = parse_time_tod(arr);
        stops[i].dep_tod = parse_time_tod(dep);
        stops[i].arr_abs = -1;
        stops[i].dep_abs = -1;
    }
    int prev_abs = -1;
    if (n > 0) {
        stops[0].dep_abs = compute_next_abs(prev_abs, stops[0].dep_tod);
        prev_abs = stops[0].dep_abs;
    }
    for (int i = 1; i < n; i++) {
        stops[i].arr_abs = compute_next_abs(prev_abs, stops[i].arr_tod);
        prev_abs = stops[i].arr_abs;
        if (i < n - 1) {
            stops[i].dep_abs = compute_next_abs(prev_abs, stops[i].dep_tod);
            prev_abs = stops[i].dep_abs;
        }
    }

    for (int i = 0; i < q; i++) {
        char s1[NAME_LEN], s2[NAME_LEN];
        if (scanf("%31s %31s", s1, s2) != 2) return 0;
        int idx1 = find_stop_index(stops, n, s1);
        int idx2 = find_stop_index(stops, n, s2);
        if (idx1 < 0 || idx2 < 0) {
            printf("0.0000000000\n");
            continue;
        }

        int time_min = stops[idx2].arr_abs - stops[idx1].dep_abs;
        double d1 = get_distance_by_name(s1);
        double d2 = get_distance_by_name(s2);
        double dist = fabs(d2 - d1);
        double speed = dist * 60.0 / (double)time_min;
        printf("%.10f\n", speed);
    }

    return 0;
}