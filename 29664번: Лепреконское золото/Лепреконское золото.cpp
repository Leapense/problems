#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> positions(n);
    for (int &x: positions) cin >> x;

    int c;
    cin >> c;

    c--;

    int x_c = positions[c];
    int x1 = positions[0];
    int xn = positions[n - 1];
    int distance_left = x_c - x1;
    int distance_right = xn - x_c;
    long long total_time;


    vector<int> order;
    if (distance_left <= t) {
        total_time = xn - x1;

        for (int i = 0; i < n; i++) order.push_back(i + 1);
    } else if (distance_right <= t) {
        total_time = xn - x1;
        for (int i = n - 1; i >= 0; i--) order.push_back(i + 1);
    } else {
        if (distance_left <= distance_right) {
            total_time = distance_left + (xn - x1);

            order.push_back(c + 1);
            for (int i = c - 1; i >= 0; i--) order.push_back(i + 1);
            for (int i = c + 1; i < n; i++) order.push_back(i + 1);
        } else {
            total_time = distance_right + (xn - x1);
            order.push_back(c + 1);
            for (int i = c + 1; i < n; i++) order.push_back(i + 1);
            for (int i = c - 1; i >= 0; i--) order.push_back(i + 1);
        }
    }

    cout << total_time << "\n";
    for (int i = 0; i < order.size(); i++) cout << order[i] << (i < order.size() - 1 ? " " : "\n");

    return 0;
}