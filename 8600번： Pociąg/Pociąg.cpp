#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> wagons(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &wagons[i]);
    }

    vector<int> cities(n);
    unordered_map<int, int> m_pos;  // resource -> position in cities
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cities[i]);
        m_pos[cities[i]] = i + 1;  // positions are 1-based
    }

    // Reverse the wagon list
    vector<int> wagons_rev(n);
    for (int i = 0; i < n; ++i) {
        wagons_rev[i] = wagons[n - i - 1];
    }

    long long pos = 0;
    for (int i = 0; i < n; ++i) {
        int r = wagons_rev[i];
        int m = m_pos[r];
        long long delta = pos + 1 - m;
        long long k = (delta + n - 1) / n;
        if (k < 0) k = 0;
        long long p = m + k * n;
        pos = p;
    }

    long long laps = (pos - 1) / n;
    printf("%lld\n", laps);
    return 0;
}