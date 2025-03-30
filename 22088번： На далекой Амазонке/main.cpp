#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (b > n - 1 || a > b) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }

        vector<vector<int>> children(n + 1);

        if (a == 0 && b == 0) {
            for (int i = 1; i <= n; i++) {
                cout << 0 << "\n";
            }
            continue;
        }

        for (int i = 1; i <= a; i++) {
            children[i].push_back(i + 1);
        }

        int extra = b - a;
        for (int i = a + 2; i <= a + 1 + extra; i++) {
            children[1].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            cout << children[i].size();
            for (int child : children[i]) {
                cout << " " << child;
            }
            cout << "\n";
        }
    }

    return 0;
}
