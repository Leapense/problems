#pragma GCC optimize ("O3,unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n; // Number of teams
    long long m; // Total number of tasks in the competition
    cin >> n >> m;
    
    vector<long long> tasks(n); // Tasks solved by each team
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }

    // Vector to keep track of additional submissions each team can make
    vector<long long> additionalTasks(n, 0);

    // Traverse each team and calculate how many tasks can be submitted by each team
    for (int i = n - 1; i >= 0; i--) {
        // Team can submit tasks as long as it keeps the beautiful condition
        while (tasks[i] < m && m % (tasks[i] + 1) == 0) {
            tasks[i]++;
            additionalTasks[i]++;
        }
    }

    // Sum up all additional tasks that can be submitted
    long long totalAdditionalTasks = 0;
    for (int i = 0; i < n; i++) {
        totalAdditionalTasks += additionalTasks[i];
    }

    cout << totalAdditionalTasks << endl;

    return 0;
}