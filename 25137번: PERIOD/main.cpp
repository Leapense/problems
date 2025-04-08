#include <iostream>
#include <string>
#include <numeric>
#include <cstdlib>
using namespace std;

long long toLL(const string& s) {
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    string s = input.substr(2);
    int L = s.size();
    int x = 0, y = 0;
    bool found = false;

    for (int candidateY = 1; candidateY * 3 <= L; candidateY++) {
        int candidateX = L - 3 * candidateY;
        string rep = s.substr(candidateX, candidateY);
        if (s.substr(candidateX + candidateY, candidateY) == rep && s.substr(candidateX + 2 * candidateY, candidateY) == rep) {
            x = candidateX;
            y = candidateY;
            found = true;
            break;
        }
    }
    long long numerator, denominator;
    if (x == 0) {
        long long repVal = toLL(s.substr(0, y));
        numerator = repVal;
        denominator = 1;
        for (int i = 0; i < y; i++) denominator *= 10;
        denominator -= 1;
    } else {
        long long whole = toLL(s.substr(0, x + y));
        long long nonRep = toLL(s.substr(0, x));
        numerator = whole - nonRep;
        denominator = 1;
        for (int i = 0; i < x + y; i++) denominator *= 10;
        long long nonRepDen = 1;

        for (int i = 0; i < x; i++) nonRepDen *= 10;
        denominator -= nonRepDen;
    }

    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << numerator << "\n" << denominator << "\n";
    return 0;
}
