#include <iostream>
#include <vector>

constexpr long long MOD = 1000000009LL;

auto add_mod = [](long long a, long long b) -> long long {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
};

int main() {
    int T;
    if (!(std::cin >> T)) {
        return 1;
    }

    std::vector<int> queries(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        if (!(std::cin >> queries[i])) {
            return 1;
        }
        if (queries[i] > max_n) {
            max_n = queries[i];
        }
    }

    std::vector<long long> odd(max_n + 4, 0);
    std::vector<long long> even(max_n + 4, 0);

    even[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        long long new_odd = 0;
        long long new_even = 0;

        if (i - 1 >= 0) {
            new_odd = add_mod(new_odd, even[i - 1]);
            new_even = add_mod(new_even, odd[i - 1]);
        }
        if (i - 2 >= 0) {
            new_odd = add_mod(new_odd, even[i - 2]);
            new_even = add_mod(new_even, odd[i - 2]);
        }
        if (i - 3 >= 0) {
            new_odd = add_mod(new_odd, even[i - 3]);
            new_even = add_mod(new_even, odd[i - 3]);
        }

        odd[i] = new_odd;
        even[i] = new_even;
    }

    for (const auto n : queries) {
        std::cout << odd[n] << ' ' << even[n] << '\n';
    }

    return 0;
}