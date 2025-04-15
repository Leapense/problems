#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    long long counts[26] = {0};

    for (int i = 0; i < n; ++i) {
        std::string handle;
        std::cin >> handle;
        if (!handle.empty()) {
            counts[handle[0] - 'A']++;
        }
    }

    long long result = 0;
    char l1 = s[0];
    char l2 = s[1];
    char l3 = s[2];

    int idx1 = l1 - 'A';
    int idx2 = l2 - 'A';
    int idx3 = l3 - 'A';

    if (l1 == l2 && l2 == l3) {
        long long k = counts[idx1];
        if (k >= 3) {
            result = k * (k - 1) * (k - 2) / 6;
        }
    } else if (l1 == l2 || l1 == l3 || l2 == l3) {
        int idx_rep, idx_uniq;
        if (l1 == l2) {
            idx_rep = idx1;
            idx_uniq = idx3;
        } else if (l1 == l3) {
            idx_rep = idx1;
            idx_uniq = idx2;
        } else {
            idx_rep = idx2;
            idx_uniq = idx1;
        }

        long long k = counts[idx_rep];
        long long m = counts[idx_uniq];


        if (k >= 2 && m >= 1) {
            result = (k * (k - 1) / 2) * m;
        }
    }
    else {
        long long c1 = counts[idx1];
        long long c2 = counts[idx2];
        long long c3 = counts[idx3];

        if (c1 >= 1 && c2 >= 1 && c3 >= 1) {
            result = c1 * c2 * c3;
        }
    }

    std::cout << result << std::endl;

    return 0;
}