#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> prefix(N + 1, vector<int>(4, 0));

    for (int i = 1; i <= N; ++i) {
        int breed;
        cin >> breed;

        prefix[i] = prefix[i - 1];
        prefix[i][breed]++;
    }

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;

        int holsteins = prefix[b][1] - prefix[a - 1][1];
        int guernseys = prefix[b][2]  - prefix[a - 1][2];
        int jerseys = prefix[b][3] - prefix[a - 1][3];
        cout << holsteins << " " << guernseys << " " << jerseys << "\n";
    }

    return 0;
}