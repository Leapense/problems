#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    int max_perimeter = 2 * (n + m);

    vector<long long> total_perimeters(max_perimeter + 1, 0);

    for (int h = 1; h <= n; ++h) {
        int count_h = n - h + 1;
        for (int w = 1; w <= m; ++w) {
            int count_w = m - w + 1;
            long long count = (long long)count_h * count_w;
            int perimeter = 2 * (h + w);
            total_perimeters[perimeter] += count;
        }
    }
    long long total = 0;

    for (int i = p; i <= max_perimeter; ++i) {
        total += total_perimeters[i];
    }

    cout << total << endl;
    return 0;
}