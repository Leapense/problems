#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;

    while(Q--) {
        int TA, TB, VA, VB;
        cin >> TA >> TB >> VA >> VB;

        int min_time = INT32_MAX;

        for (int x = 0; x <= VA; x++) {
            int time_Sanghyeok = x * TA;
            int time_Dohun = (VA - x) * TA + VB * TB;
            int current_max = max(time_Sanghyeok, time_Dohun);
            min_time = min(min_time, current_max);
        }

        cout << min_time << "\n";
    }
    
    return 0;
}