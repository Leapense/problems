#include <iostream>
#include <algorithm>

int main() {
    int l1, r1, l2, r2, k;
    std::cin >> l1 >> r1 >> l2 >> r2 >> k;

    // Calculate the maximum of the start times and the minimum of the end times
    int start = std::max(l1, l2);
    int end = std::min(r1, r2);

    // If the meeting interval is valid (start is less than or equal to end)
    if (start <= end) {
        // Calculate the total overlap time
        int total_time = end - start + 1;
        // If k falls within the overlapping interval, reduce the time by 1
        if (k >= start && k <= end) {
            total_time--;
        }
        std::cout << total_time << std::endl;
    } else {
        // If there is no overlapping interval, output 0
        std::cout << 0 << std::endl;
    }

    return 0;
}