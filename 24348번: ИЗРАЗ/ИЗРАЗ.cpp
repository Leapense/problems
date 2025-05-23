#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Possible permutations of a, b, c
    vector<vector<int>> permutations = {
        {a, b, c},
        {a, c, b},
        {b, a, c},
        {b, c, a},
        {c, a, b},
        {c, b, a}
    };

    int max_value = INT_MIN;

    // Evaluate all expressions
    for (const auto& p : permutations) {
        // p[0], p[1], p[2] represent the three numbers in the current permutation
        int x = p[0], y = p[1], z = p[2];
        // All possible combinations of operations between the three numbers
        max_value = max(max_value, x + y + z);
        max_value = max(max_value, x + y - z);
        max_value = max(max_value, x + y * z);
        max_value = max(max_value, x - y + z);
        max_value = max(max_value, x - y - z);
        max_value = max(max_value, x - y * z);
        max_value = max(max_value, x * y + z);
        max_value = max(max_value, x * y - z);
        max_value = max(max_value, x * y * z);
    }

    cout << max_value << endl;
    return 0;
}