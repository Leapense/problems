#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int N;
        cin >> N;
        int res = N / 4 + 1;

        cout << "Case #" << case_num << ": " << res << endl;
    }

    return 0;
}