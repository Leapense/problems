#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    vector<int> m(n);
    int total_base = 0;
    int num_extra_pieces = 0;

    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        total_base += m[i] / 2;
        if (m[i] % 2 != 0) {
            num_extra_pieces++;
        }
    }

    int total_sushi = total_base * 2 + num_extra_pieces;

    int lb = max({total_base, x1, total_sushi - y2});
    int ub = min({total_base + num_extra_pieces, y1, total_sushi - x2});

    if (lb <= ub) {
        cout << "Yes" <<  endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}