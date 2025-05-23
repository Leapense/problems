#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<long long> sums(N-1);
    for (int i = 0; i < N-1; i++) {
        std::cin >> sums[i];
    }
    
    long long total_sum;
    std::cin >> total_sum;
    
    // Calculate the sum of S1, S2, ..., S(N-1)
    long long sum_of_sums = 0;
    for (int i = 0; i < N-1; i++) {
        sum_of_sums += sums[i];
    }
    
    // Compute aN
    long long aN = (sum_of_sums - total_sum) / (N - 2);
    
    // Output each number a1, a2, ..., aN-1
    for (int i = 0; i < N-1; i++) {
        std::cout << sums[i] - aN << "\n";
    }
    
    // Output aN
    std::cout << aN << "\n";
    
    return 0;
}