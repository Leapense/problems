#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    int n;
    if (!(std::cin >> k >> n)) {
        return 0;
    }

    std::vector<int> first_residue_index(k, -1);
    int prefix = 0;
    int start_index = -1;
    int end_index = -1;

    for (int i = 0; i < k; ++i) {
        int value;
        if (!(std::cin >> value)) {
            return 0;
        }
        prefix = (prefix + (value % k)) % k;
        if (prefix == 0) {
            start_index = 0;
            end_index = i;
            break;
        }
        if (first_residue_index[prefix] != -1) {
            start_index = first_residue_index[prefix] + 1;
            end_index = i;
            break;
        }
        first_residue_index[prefix] = i;
    }

    for (int i = k; i < n; ++i) {
        int discard;
        std::cin >> discard;
    }

    if (start_index == -1 || end_index == -1) {
        std::cout << "no kravaiche\n";
        return 0;
    }

    for (int i = start_index; i <= end_index; ++i) {
        if (i > start_index) {
            std::cout << ' ';
        }
        std::cout << (i + 1);
    }
    std::cout << '\n';
    return 0;
}