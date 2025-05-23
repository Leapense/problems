#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N, A, D;
        cin >> N >> A >> D; // Read N, A, and D for each test case
        
        // Calculate the sum of the arithmetic progression
        int total = N * (2 * A + (N - 1) * D) / 2;
        
        // Output the total number of cookies
        cout << total << endl;
    }
    return 0;
}