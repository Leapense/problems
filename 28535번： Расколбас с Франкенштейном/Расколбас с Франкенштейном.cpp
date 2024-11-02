#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    string input;
    getline(cin, input);

    string c1_str, op_str, c2_str;

    int idx = 0;

    while (idx < input.size() && input[idx] == ' ') idx++;
    c1_str = input[idx++];
    while (idx < input.size() && input[idx] == ' ') idx++;
    op_str = input[idx++];
    while (idx < input.size() && input[idx] == ' ') idx++;
    c2_str = input[idx++];

    char c1 = c1_str[0];
    char op = op_str[0];
    char c2 = c2_str[0];

    map<char, int> class_order = {
        {'N', 1},
        {'Z', 2},
        {'Q', 3},
        {'R', 4}
    };

    char result_class;

    if (op == '+') {
        if (c1 == 'N' && c2 == 'N') {
            result_class = 'N';
        } else {
            int max_order = max(class_order[c1], class_order[c2]);
            for (auto& pair : class_order) {
                if (pair.second == max_order) {
                    result_class = pair.first;
                    break;
                }
            }
        }
    } else if (op == '-') {
        if (c1 == 'N' && c2 == 'N') {
            result_class = 'Z';
        } else {
            int max_order = max(class_order[c1], class_order[c2]);
            for (auto& pair : class_order) {
                if (pair.second == max_order) {
                    result_class = pair.first;
                    break;
                }
            }
        }
    } else if (op == '*') {
        if (c1 == 'N' && c2 == 'N') {
            result_class = 'N';
        } else {
            int max_order = max(class_order[c1], class_order[c2]);
            for (auto& pair : class_order) {
                if (pair.second == max_order) {
                    result_class = pair.first;
                    break;
                }
            }
        }
    }

    cout << result_class << '\n';

    return 0;
}