#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, l;
        std::cin >> n >> l;
        std::vector<int> grisha(n);
        std::vector<int> dima(n);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> grisha[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> dima[i];
        }
        
        // Sort both arrays in ascending order
        std::sort(grisha.begin(), grisha.end());
        std::sort(dima.begin(), dima.end());
        
        // Calculate the sum of the weakest l elements from Grisha
        int sum_grisha = std::accumulate(grisha.begin(), grisha.begin() + l, 0);
        // Calculate the sum of the strongest l elements from Dima
        int sum_dima = std::accumulate(dima.end() - l, dima.end(), 0);
        
        // Grisha wins if his weakest sum is still greater than Dima's strongest sum
        if (sum_grisha > sum_dima) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}