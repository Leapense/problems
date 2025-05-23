#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int N;
    cin >> N;

    vector<int> seats(N + 1);
    for (int i = 1; i <= N; i++) cin >> seats[i];

    int count = 0;
    int current_seat = 1;

    while(seats[current_seat] != 0) {
        int X = seats[current_seat];
        count++;
        seats[current_seat] = 0;
        current_seat = X;
    }

    cout << count;

    return 0;
}