#include <iostream>
using namespace std;

string isThreesomeNumber(long long N) {
    while (N > 0) {
        if (N % 3 > 1) {
            return "NO";
        }
        N /= 3;
    }

    return "YES";
}

int main() {
    long long N;
    cin >> N;
    cout << isThreesomeNumber(N) << endl;

    return 0;
}