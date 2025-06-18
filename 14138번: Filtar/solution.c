#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __int128_t int128;
typedef long long ll;

typedef struct {
    ll x, y;
} Point;

int compare_points(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    return 0;
}

int compare_ll(const void* a, const void* b) {
    ll val1 = *(ll*)a;
    ll val2 = *(ll*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int n;
Point* input_points;
int d;

ll get_u(ll k) {
    int low = 0, high = n - 1, idx = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (input_points[mid].x <= k) {
            idx = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    const Point* p1;
    const Point* p2;

    if (k < input_points[0].x) {
        p1 = &input_points[0];
        p2 = &input_points[1];
    } else if (k >= input_points[n - 1].x) {
        p1 = &input_points[n - 2];
        p2 = &input_points[n - 1];
        if (k == input_points[n - 1].x) return input_points[n - 1].y;
    } else {
        p1 = &input_points[idx];
        p2 = &input_points[idx + 1];
        if (k == p1->x) return p1->y;
    }

    ll x1 = p1->x, y1 = p1->y;
    ll x2 = p2->x, y2 = p2->y;

    ll slope = (y2 - y1) / (x2 - x1);
    return y1 + (k - x1) * slope;
}

ll get_y(ll k) {
    ll* values = (ll*)malloc(sizeof(ll) * (2 * d + 1));
    for (int i = -d; i <= d; ++i) {
        values[i + d] = get_u(k - i);
    }
    qsort(values, 2 * d + 1, sizeof(ll), compare_ll);
    ll median = values[d];
    free(values);
    return median;
}

typedef struct {
    Point* data;
    size_t size;
    size_t capacity;
} PointVector;

void pv_init(PointVector* v) { v->data = NULL; v->size = v->capacity = 0; }
void pv_push_back(PointVector* v, Point p) {
    if (v->size == v->capacity) {
        v->capacity = (v->capacity == 0) ? 8 : v->capacity * 2;
        v->data = (Point*)realloc(v->data, v->capacity * sizeof(Point));
    }

    v->data[v->size++] = p;
}

int main()
{
    scanf("%d", &n);
    input_points = (Point*)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &input_points[i].x, &input_points[i].y);
    }
    scanf("%d", &d);

    ll* event_x_arr = (ll*)malloc(sizeof(ll) * n * (2 * d + 1));
    int event_count = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = -d; i <= d; ++i) {
            event_x_arr[event_count++] = input_points[j].x + i;
        }
    }

    qsort(event_x_arr, event_count, sizeof(ll), compare_ll);

    int unique_count = 0;
    if (event_count > 0) {
        unique_count = 1;
        for (int i = 1; i < event_count; i++) {
            if (event_x_arr[i] != event_x_arr[i - 1]) {
                event_x_arr[unique_count++] = event_x_arr[i];
            }
        }
    }

    event_count = unique_count;

    PointVector result_points;
    pv_init(&result_points);

    for (int i = 0; i < event_count; ++i) {
        ll x = event_x_arr[i];
        ll y = get_y(x);
        Point p = {x, y};

        if (result_points.size >= 2) {
            Point p2 = result_points.data[result_points.size - 1];
            Point p1 = result_points.data[result_points.size - 2];
            int128 x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y, x3 = p.x, y3 = p.y;
            if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
                result_points.data[result_points.size - 1] = p;
            } else {
                pv_push_back(&result_points, p);
            }
        } else {
            pv_push_back(&result_points, p);
        }
    }

    printf("%zu\n", result_points.size);
    for (size_t i = 0; i < result_points.size; ++i) {
        printf("%lld %lld\n", result_points.data[i].x, result_points.data[i].y);
    }

    free(input_points);
    free(event_x_arr);
    free(result_points.data);

    return 0;
}