#include <bits/stdc++.h>
using namespace std;

struct MatrixInfo {
    int rows;
    int cols;
    long long cost;
    bool error;
};

MatrixInfo parse_expression(const string &expr, int &index, const unordered_map<char, pair<int, int>> &matrix_map) {
    if (index >= expr.size()) {
        return MatrixInfo{0, 0, 0, true};
    }

    if (expr[index] == '(') {
        index++;

        MatrixInfo left = parse_expression(expr, index, matrix_map);
        if (left.error) {
            return MatrixInfo{0, 0, 0, true};
        }

        MatrixInfo right = parse_expression(expr, index, matrix_map);
        if (right.error) {
            return MatrixInfo{0, 0, 0, true};
        }

        if (index >= expr.size() || expr[index] != ')') {
            return MatrixInfo{0, 0, 0, true};
        }
        index++;

        if (left.cols != right.rows) {
            return MatrixInfo{0, 0, 0, true};
        }

        long long current_cost = static_cast<long long>(left.rows) * left.cols * right.cols;

        long long total_cost = left.cost + right.cost + current_cost;
        return MatrixInfo{left.rows, right.cols, total_cost, false};
    } else if (isupper(expr[index])) {
        char matrix_name = expr[index];
        index++;

        auto it = matrix_map.find(matrix_name);
        if (it == matrix_map.end()) {
            return MatrixInfo{0, 0, 0, true};
        }

        return MatrixInfo{it->second.first, it->second.second, 0, false};
    } else {
        return MatrixInfo{0, 0, 0, true};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    unordered_map<char, pair<int, int>> matrix_map;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        char name;
        int rows, cols;

        ss >> name >> rows >> cols;
        matrix_map[name] = {rows, cols};
    }

    string expr;

    while(getline(cin, expr)) {
        if (expr.empty()) {
            cout << "error\n";
            continue;
        }
        int index = 0;
        MatrixInfo result = parse_expression(expr, index, matrix_map);

        if (!result.error && index == expr.size()) {
            cout << result.cost << "\n";
        } else {
            cout << "error\n";
        }
    }

    return 0;
}