#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// Function to compute GCD of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to determine the elimination round for a given fraction
int find_elimination_round(long long numerator, long long denominator, int max_round = 20) {
    numerator *= 3;
    for (int k = 1; k <= max_round; ++k) {
        long long digit = numerator / denominator;
        if (digit == 1) {
            return k;
        } else if (digit == 2) {
            numerator -= 2 * denominator;
        } else if (digit == 0) {
            // Do nothing
        }
        if (numerator == 0) {
            return 1000; // Never eliminated
        }
        numerator *= 3;
    }
    return 1000; // Never eliminated if no '1' found within max_round
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<pair<int, double>> numbers;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            size_t dot_pos = s.find('.');
            string decimal_part = s.substr(dot_pos + 1);
            int l = decimal_part.length();
            long long numerator = stoll(decimal_part);
            long long denominator = 1;
            for (int j = 0; j < l; ++j) {
                denominator *= 10;
            }
            // Simplify the fraction
            long long common = gcd(numerator, denominator);
            numerator /= common;
            denominator /= common;
            // Find elimination round
            int round = find_elimination_round(numerator, denominator);
            // Store the number as double for sorting
            double number = stod(s);
            numbers.push_back({round, number});
        }
        // Sort numbers by elimination round and numerical value
        sort(numbers.begin(), numbers.end());
        // Output
        cout << "Case #" << t << ":" << endl;
        for (auto& num : numbers) {
            cout << num.second << endl;
        }
    }
    return 0;
}