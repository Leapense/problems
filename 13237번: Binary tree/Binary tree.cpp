#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_height(int node, const vector<int>& parents) {
    if (parents[node - 1] == -1) {
        return 0;
    } else {
        return 1 + get_height(parents[node - 1], parents);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> parents(n);
    for (int i = 0; i < n; ++i) {
        cin >> parents[i];
    }

    for (int i = 1; i <= n; ++i) {
        cout << get_height(i, parents) << "\n";
    }

    return 0;
}