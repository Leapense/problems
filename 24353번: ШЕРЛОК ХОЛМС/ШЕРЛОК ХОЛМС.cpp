#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Function to check if a five-digit number is divisible by any sum of N1, N2, and N3
bool isDivisible(int N1, int N2, int N3) {
    int number = stoi(to_string(N1) + to_string(N2) + to_string(N3));
    int sum1 = N1 + N2;
    int sum2 = N1 + N3;
    int sum3 = N2 + N3;
    return (number % sum1 == 0) || (number % sum2 == 0) || (number % sum3 == 0);
}

int main() {
    int N, s, M;
    cin >> N >> s >> M;

    vector<int> counts(12, 0);
    vector<vector<int>> combinations(12);

    // Iterate through each month
    for (int month = 1; month <= 12; ++month) {
        int N1 = month + 10;
        int N2 = s;
        set<int> excluded;
        
        // Exclude numbers from 11 to 22
        for (int i = 1; i <= 12; ++i) {
            excluded.insert(i + 10);
        }

        // Find valid N3
        for (int N3 = 10; N3 <= N; ++N3) {
            if (excluded.count(N3) == 0) {
                if (isDivisible(N1, N2, N3)) {
                    counts[month - 1]++;
                    // If the month matches the current month, track this combination
                    if (month == M) {
                        combinations[month - 1] = {N1, N2, N3};
                        break; // Select the smallest N3
                    }
                }
            }
        }
    }

    // Output counts for all months
    for (int count : counts) {
        cout << count << endl;
    }

    // Output the combination for the current month
    if (!combinations[M - 1].empty()) {
        cout << combinations[M - 1][0] << " " << combinations[M - 1][1] << " " << combinations[M - 1][2] << endl;
    } else {
        cout << "0 0 0" << endl;
    }

    return 0;
}