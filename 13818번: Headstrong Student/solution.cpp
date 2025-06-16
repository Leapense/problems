#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

void solve(int x, int y) {
    std::vector<int> remainders_seen(y, -1);
    int position = 0;
    int remainder = x;

    while (true) {
        if (remainders_seen[remainder] != -1) {
            int non_recurring_len = remainders_seen[remainder];
            int recurring_len = position - non_recurring_len;
            std::cout << non_recurring_len << " " << recurring_len << "\n";
            return;
        }

        remainders_seen[remainder] = position;

        remainder = (remainder * 10) % y;
        position++;

        if (remainder == 0) {
            std::cout << position << " 0\n";
            return;
        }
    }
}

int main() {
    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    while (std::cin >> x >> y && (x != 0 || y != 0)) {
        solve(x, y);
    }

    return 0;
}