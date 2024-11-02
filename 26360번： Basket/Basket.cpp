#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int X;
    cin >> X;
    int shot_result;
    cin >> shot_result;
    int foul;
    cin >> foul;
    int total_points = 0;

    if (shot_result == 1) total_points += X;

    if (foul == 1) {
        if (shot_result == 1) {
            int free_throw;
            cin >> free_throw;

            if (free_throw == 1) total_points += 1;
        } else {
            for (int i = 0; i < X; i++) {
                int free_throw;
                cin >> free_throw;

                if (free_throw == 1) total_points += 1;
            }
        }
    }

    cout << total_points << "\n";

    return 0;
}