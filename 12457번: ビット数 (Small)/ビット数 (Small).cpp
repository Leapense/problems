#include <iostream>
#include <bitset>

using namespace std;

int countOnes(int x) {
    return bitset<32>(x).count();
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        int maxSum = 0;

        for (int a = 0; a <= N; ++a) {
            int b = N - a;
            int sum = countOnes(a) + countOnes(b);
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        cout << "Case #" << t << ": " << maxSum << endl;
    }

    return 0;
}