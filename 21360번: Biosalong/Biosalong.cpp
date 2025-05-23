#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N;
    cin >> N;
    string seats;
    cin >> seats;

    vector<int> freeSeats;

    for (int i = 0; i < N; i++) {
        if (seats[i] == '.') {
            freeSeats.push_back(i);
        }
    }

    int minDistance = N;

    for (int i = 1; i < freeSeats.size(); i++) {
        minDistance = min(minDistance, freeSeats[i] - freeSeats[i - 1] - 1);
    }

    cout << minDistance << endl;

    return 0;
}