#include <iostream>
#include <vector>
#include <numeric>

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    std::vector<int> path(n);
    int max_city_id = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> path[i];
        if (path[i] > max_city_id) {
            max_city_id = path[i];
        }
    }

    int num_cities = max_city_id + 1;
    std::vector<int> parent(num_cities);
    std::vector<bool> visited(num_cities, false);

    int root = path[0];
    parent[root] = -1;
    visited[root] = true;

    for (int i = 1; i < n; ++i) {
        int prev_city = path[i - 1];
        int current_city = path[i];
        if (!visited[current_city]) {
            visited[current_city] = true;
            parent[current_city] = prev_city;
        }
    }
    std::cout << num_cities << "\n";
    for (int i = 0; i < num_cities; ++i) {
        std::cout << parent[i] << (i == num_cities - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}