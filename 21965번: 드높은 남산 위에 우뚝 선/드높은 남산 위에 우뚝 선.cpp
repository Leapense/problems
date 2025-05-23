#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    bool check = true;  // To verify if it's a mountain
    bool shape = true;  // To check for only one increase then decrease without increase again
    
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1]) {
            if (!shape) { // Was decreasing and now increasing again
                check = false;
                break;
            }
        } else if (A[i] == A[i + 1]) { // Equal heights
            check = false;
            break;
        } else { // A[i] > A[i + 1] - Starting to decrease
            shape = false;
        }
    }
    
    if (check) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
