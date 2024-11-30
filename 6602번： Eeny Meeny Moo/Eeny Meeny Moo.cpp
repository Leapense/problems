#include <bits/stdc++.h>
using namespace std;

bool isLastEliminated2(int n, int m) {
    vector<int> cities;
    for (int i = 1; i <= n; ++i) {
        cities.push_back(i);
    }

    vector<int> elimination_order;

    auto it = find(cities.begin(), cities.end(), 1);
    if(it != cities.end()) {
        elimination_order.push_back(1);
        cities.erase(it);
    }

    int current_index = 0;

    while(!cities.empty()) {
        int size = cities.size();
        int eliminate_index = (current_index + m - 1) % size;
        int eliminated_city = cities[eliminate_index];
        elimination_order.push_back(eliminated_city);
        cities.erase(cities.begin() + eliminate_index);
        current_index = eliminate_index % (cities.empty() ? 1 : cities.size());
    }

    return elimination_order.back() == 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    while(cin >> n) {
        if(n == 0) break;

        int m = 1;

        while (true) {
            if(isLastEliminated2(n, m)) {
                cout << m << "\n";
                break;
            }
            m++;

            if (m > 10000) {
                cout << "No solution found for n = " << n << "\n";
                break;
            }
        }
    }

    return 0;
}