#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> y_to_x(10001, vector<int>());
    vector<vector<int>> x_to_y(10001, vector<int>());
    
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        y_to_x[y].push_back(x);
        x_to_y[x].push_back(y);
    }

    long long perimeter = 0;

    for (int y = 0; y <= 10000; y++) {
        if (y_to_x[y].size() >= 2) {
            vector<int> &xs = y_to_x[y];

            sort(xs.begin(), xs.end());
            for (int i = 0; i < xs.size(); i += 2) {
                perimeter += (long long)(xs[i + 1] - xs[i]);
            }
        }
    }

    for (int x = 0; x <= 10000; x++) {
        if (x_to_y[x].size() >= 2) {
            vector<int> &ys = x_to_y[x];
            sort(ys.begin(), ys.end());

            for (int i = 0; i < ys.size(); i += 2) {
                perimeter += (long long)(ys[i + 1] - ys[i]);
            }
        }
    }

    cout << perimeter << "\n";

    return 0;
}