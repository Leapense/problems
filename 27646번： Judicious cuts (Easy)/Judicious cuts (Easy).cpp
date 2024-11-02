#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int t;
    cin >> t;
    cin.ignore();

    for (int test_case = 1; test_case <= t; ++test_case) {
        if (test_case > 1) {
            string blank_line;
            getline(cin, blank_line);
        }

        string input_line;
        while (getline(cin, input_line)) {
            if (!input_line.empty()) {
                break;
            }
        }

        int n = stoi(input_line);
        if (n == 1) {
            cout << "0\n";
        } else {
            int l = n - 1;
            cout << l << "\n";

            for (int i = 1; i <= l; ++i) {
                cout << "0 " << i << "\n";
            }
        }
    }

    return 0;
}