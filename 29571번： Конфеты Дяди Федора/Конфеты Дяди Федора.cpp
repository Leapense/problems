#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    
    // Precompute tetrahedral numbers up to 1e9
    std::vector<long long> tetras;
    tetras.push_back(0); // T(0) = 0
    int N_max = 0;
    long long T_N = 0;
    for (int N = 1;; N++) {
        long long T_N = N * (N + 1LL) * (N + 2LL) / 6LL;
        if (T_N > 1e9)
            break;
        tetras.push_back(T_N);
        N_max = N;
    }
    
    bool found = false;
    for (int N = 1; N <= N_max; N++) {
        T_N = tetras[N];
        if (T_N < n)
            continue;
        long long T_kminus1 = T_N - n;
        if (T_kminus1 < 1)
            continue;
        // Binary search for T_kminus1 in tetras[1..N-1]
        auto it = std::lower_bound(tetras.begin(), tetras.end(), T_kminus1);
        if (it != tetras.end() && *it == T_kminus1) {
            int idx = it - tetras.begin();
            int k = idx; // Since tetras[0] = 0
            if (k >= 2 && k <= N) {
                found = true;
                break;
            }
        }
    }
    if (found)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}