#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    if (n == 0) {
        return;
    }

    std::unordered_map<int, int> balance;
    int unbalanced_count = 0;
    std::vector<int> partition_points;
    
    for (int i = 0; i < n; ++i) {
        int val_a = a[i];
        int val_b = b[i];

        if (balance.find(val_a) == balance.end()) balance[val_a] = 0;
        if (balance[val_a] == 0) unbalanced_count++;
        balance[val_a]++;
        if (balance[val_a] == 0) unbalanced_count--;

        if (balance.find(val_b) == balance.end()) balance[val_b] = 0;
        if (balance[val_b] == 0) unbalanced_count++;
        balance[val_b]--;
        if (balance[val_b] == 0) unbalanced_count--;

        if (unbalanced_count == 0) {
            partition_points.push_back(i);
        }
    }

    int current_partition = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << b[i];
        if (current_partition < partition_points.size() && i == partition_points[current_partition]) {
            if (i < n - 1) {
                std::cout << " #";
            }
            current_partition++;
        }
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}