#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> pos_in_b(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        pos_in_b[b[i]] = i;
    }

    vector<bool> visited(n, false);
    int num_cycles = 0;
    int max_cycle_len = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i] && !visited[i]) {
            num_cycles++;
            int cycle_len = 0;
            int current_pos = i;

            do {
                visited[current_pos] = true;
                cycle_len++;
                int next_cow = a[current_pos];
                current_pos = pos_in_b[next_cow];
            } while (current_pos != i);

            max_cycle_len = max(max_cycle_len, cycle_len);
        }
    }

    cout << num_cycles << " " << max_cycle_len << "\n";

    return 0;
}