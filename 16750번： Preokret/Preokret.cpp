#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A;
    cin >> A;
    vector<int> A_times(A);
    for (auto &x: A_times) cin >> x;

    int B;
    cin >> B;
    vector<int> B_times(B);
    for (auto &x: B_times) cin >> x;

    vector<pair<int, char>> events;
    events.reserve(A + B);
    for (auto x: A_times) events.emplace_back(x, 'A');
    for (auto x: B_times) events.emplace_back(x, 'B');

    sort(events.begin(), events.end(), [&](const pair<int, char> &a, const pair<int, char> &b) -> bool {
        return a.first < b.first;
    });

    int first_half = 0;
    int turnaround = 0;
    int scoreA = 0, scoreB = 0;
    int last_leader = 0;

    int last_non_tie_leader = 0;

    for (auto &[time, team] : events) {
        if (time <= 1440) first_half++;
        if (team == 'A') scoreA++;
        else scoreB++;

        int current_leader = 0;
        if (scoreA > scoreB) current_leader = 1;
        else if (scoreB > scoreA) current_leader = 2;
        else current_leader = 0;

        if (current_leader != 0 and last_non_tie_leader != 0 and current_leader != last_non_tie_leader) {
            turnaround++;
        }

        if (current_leader != 0) {
            last_non_tie_leader = current_leader;
        }
    }

    cout << first_half << "\n" << turnaround << "\n";

    return 0;
}