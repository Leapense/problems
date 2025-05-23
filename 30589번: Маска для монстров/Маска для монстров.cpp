#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> Point;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;

    double perimeter = 0.0;
    double max_len = 0.0;

    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        long long dx = points[i].first - points[j].first;
        long long dy = points[i].second - points[j].second;
        double len = sqrt((double)dx * dx + (double)dy * dy);
        perimeter += len;
        if (len > max_len) max_len = len;
    }

    double mask_length = perimeter - max_len;

    cout << fixed << setprecision(6) << mask_length;

    return 0;
}