#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> prizes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prizes[i];
    }

    std::vector<int> max_guaranteed(n - 1);
    
    if (n > 1) {
        max_guaranteed[0] = std::min(prizes[0], prizes[1]);
        int largest = std::max(prizes[0], prizes[1]);
        int second_largest = std::min(prizes[0], prizes[1]);

        for (int k = 3; k <= n; ++k) {
            int current = prizes[k-1];
            
            if (current > largest) {
                second_largest = largest;
                largest = current;
            } else if (current > second_largest) {
                second_largest = current;
            }

            max_guaranteed[k-2] = second_largest;
        }
    }

    for (int value : max_guaranteed) {
        std::cout << value << " ";
    }
    
    std::cout << std::endl;

    return 0;
}