#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool canFormNumber(const string &numStr, const set<char> &digits) {
    for (char c : numStr) {
        if (digits.find(c) == digits.end()) 
            return false;
    }
    return true;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    cin >> N;

    vector<int> d(N);
    set<char> digits;

    bool hasZeroOrOne = false;
    bool hasCompositeDigit = false;
    int compositeDigit = -1;

    for (int i = 0; i < N; ++i) {
        cin >> d[i];
        digits.insert(d[i] + '0');

        if (d[i] == 0 || d[i] == 1) {
            hasZeroOrOne = true;
        }
        if (d[i] == 4 || d[i] == 6 || d[i] == 8 || d[i] == 9) {
            hasCompositeDigit = true;
            compositeDigit = d[i];
        }
    }

    if (hasZeroOrOne) {
        cout << "YES\n";
        cout << (digits.find('0') != digits.end() ? '0' : '1') << "\n";
        return 0;
    }

    if (hasCompositeDigit) {
        cout << "YES\n";
        cout << compositeDigit << "\n";
        return 0;
    }

    vector<int> compositeNumbers;
    vector<bool> isPrime(1000, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < 1000; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j < 1000; j += i) {
                isPrime[j] = false;
            }
        } else {
            compositeNumbers.push_back(i);
        }
    }

    for (int num : compositeNumbers) {
        string numStr = to_string(num);
        if (canFormNumber(numStr, digits)) {
            cout << "YES\n";
            cout << numStr << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}