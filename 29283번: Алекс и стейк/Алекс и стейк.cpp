#include <iostream>

int main() {
    int k;
    std::cin >> k;

    int complete_blocks = k / 5;
    int remaining_presses = k % 5;
    int total_time = 0;

    // Sum time for complete blocks
    for (int i = 1; i <= complete_blocks; ++i) {
        total_time += 5 * (i * 30);
    }

    // Sum time for remaining presses
    total_time += remaining_presses * ((complete_blocks + 1) * 30);

    std::cout << total_time << std::endl;

    return 0;
}