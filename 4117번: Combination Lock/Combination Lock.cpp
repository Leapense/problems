#include <iostream>
using namespace std;

int calculate_max_ticks(int N, int T1, int T2, int T3) {
    return 4 * N + (T2 - T1 + N) % N + (T2 - T3 + N) % N - 1;
}

int main() {
    while (true) {
        int N, T1, T2, T3;
        cin >> N >> T1 >> T2 >> T3;

        if (N == 0 && T1 == 0 && T2 == 0 && T3 == 0) {
            break;
        }

        int result = calculate_max_ticks(N, T1, T2, T3);
        cout << result << endl;
    }
    
    return 0;
}
