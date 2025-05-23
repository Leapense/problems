#include <iostream>
using namespace std;

int main()
{
    int D;
    while (cin >> D && D != 0) {
        int L = 1, R = 100;
        int side = -1;
        int count = 0;

        while (true) {
            int N;
            int first_valid, last_valid;
            int M;

            if (side == -1) {
                N = R - L + 1;
                M = L + (N - 1) / 2;
            } else {
                first_valid = (L % 2 == side) ? L : L + 1;
                last_valid = (R % 2 == side) ? R : R - 1;
                N = ((last_valid - first_valid) / 2) + 1;
                if (N <= 0) break;
                int mid_index = (N - 1) / 2;
                M = first_valid + 2 * mid_index;
            }

            count++;

            if (M == D) { break; }
            else if ((M % 2) != (D % 2)) { side = 1 - (M % 2); }
            else if (D < M) { R = M - 1; side = M % 2; }
            else { L = M + 1; side = M % 2; }
        }
        cout << count << endl;
    }


    return 0;
}