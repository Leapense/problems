#include <iostream>

bool can_visit_all_cells_k_times(long long r, long long c, long long k) {
    if (k == 1) {
        return true;
    }

    return (r * c) % 2 == 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long r, c, k;
    std::cin >> r >> c >> k;

    if (can_visit_all_cells_k_times(r, c, k)) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}