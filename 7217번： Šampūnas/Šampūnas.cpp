#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    // Read the holiday days
    unordered_set<int> holidays;
    for (int i = 0; i < K; ++i) {
        int d;
        cin >> d;
        holidays.insert(d);
    }

    // Simulation of head washing
    int wash_count = 0;
    bool washed_yesterday = false;

    for (int day = 1; day <= N; ++day) {
        if (day == 1 || holidays.count(day) || !washed_yesterday) {
            // Wash head if it's the first day, a holiday, or yesterday wasn't washed
            wash_count++;
            washed_yesterday = true;
        } else {
            // Do not wash today
            washed_yesterday = false;
        }
    }

    // Output the total number of washes
    cout << wash_count << endl;

    return 0;
}