#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int P;
    cin >> P;

    for (int p = 0; p < P; ++p) {
        int K;
        cin >> K;
        vector<int> a(15);

        for (int i = 0; i < 15; ++i) {
            cin >> a[i];
        }

        int islands = 0;

        int n = 15;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int left = (i == 0) ? 0 : a[i - 1];
                int right = (j == n - 1) ? 0 : a[j + 1];

                bool isIsland = true;

                for (int k = i; k <= j; ++k) {
                    if (a[k] <= left || a[k] <= right) {
                        isIsland = false;
                        break;
                    }
                }
                if (isIsland) {
                    ++islands;
                }
            }
        }

        cout << K << " " << islands << "\n";
    }

    return 0;
}