#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int k;
static int weights[13];
static bool possible[2600001];
static bool visited[14][5200001];
static const int OFFSET = 2600000;

void find_measurable_weights(int index, int current_sum) {
    if (visited[index][current_sum + OFFSET]) {
        return;
    }
    visited[index][current_sum + OFFSET] = true;

    if (index == k) {
        if (current_sum > 0) {
            possible[current_sum] = true;
        }
        return;
    }

    find_measurable_weights(index + 1, current_sum + weights[index]);
    find_measurable_weights(index + 1, current_sum - weights[index]);
    find_measurable_weights(index + 1, current_sum);
}

void solve() {
    scanf("%d", &k);
    long long total_sum = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &weights[i]);
        total_sum += weights[i];
    }

    find_measurable_weights(0, 0);

    int unmeasurable_count = 0;
    for (long long i = 1; i <= total_sum; ++i) {
        if (!possible[i]) {
            unmeasurable_count++;
        }
    }

    printf("%d\n", unmeasurable_count);
}

int main() {
    solve();
    return 0;
}