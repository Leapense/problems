#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

bool isPowerOfTwo (int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int findMinimalK (int P, int Q) {
    if (isPowerOfTwo(Q)) {
        return log2(Q);
    }

    return -1;
}

string fractionToBinary (int P, int Q) {
    string binary = "";
    double value = (double)P / Q;
    while (value > 0 && binary.size() < 32) {
        value *= 2;
        if (value >= 1) {
            binary += '1';
            value -= 1;
        } else {
            binary += '0';
        }
    }

    return binary;
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        string s;
        cin >> s;
        int P, Q;
        size_t slash = s.find('/');
        P = stoi(s.substr(0, slash));
        Q = stoi(s.substr(slash + 1));

        if (Q % P == 0) {
            cout << "Case #" << test << ": 0" << endl;
            continue;
        }

        int k = findMinimalK(P, Q);

        if (k != -1) {
            cout << "Case #" << test << ": " << k << endl;
        } else {
            string binary = fractionToBinary(P, Q);
            if (binary.find('1') != string::npos) {
                int pos = binary.find('1') + 1;
                cout << "Case #" << test << ": " << pos << endl;
            } else {
                cout << "Case #" << test << ": impossible" << endl;
            }
        }
    }

    return 0;
}