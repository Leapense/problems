#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int m_x = x[2];
    int m_y = y[2];

    int total_menhatten_distance = 0;

    for (int i = 0; i < n; i++)
    {
        total_menhatten_distance += abs(x[i] - m_x) + abs(y[i] - m_y);
    }

    cout << total_menhatten_distance << "\n";

    return 0;
}