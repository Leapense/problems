#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    string M;
    cin >> N >> M;

    int R, cc;
    sscanf(M.c_str(), "%d,%d", &R, &cc);

    string best_name = "-1";
    int max_cost = -1;

    for (int i = 0; i < N; ++i) {
        string name, price;
        cin >> name >> price;

        int s_i, t_i;
        sscanf(price.c_str(), "%d,%d", &s_i, &t_i);

        if (s_i > R || t_i > cc) {
            continue;
        }

        int cost = s_i * 100 + t_i;

        if (cost > max_cost) {
            max_cost = cost;
            best_name = name;
        }
    }

    cout << best_name << "\n";

    return 0;
}