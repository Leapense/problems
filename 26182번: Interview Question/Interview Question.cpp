#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_a(long long a, int c, int d, const vector<string>& transcript) {
    if (a <= 0) return false;
    for (int i = 0; i <= d - c; ++i) {
        long long num = (long long) c + i;
        const string& entry = transcript[i];
        
        bool required_a_multiple = (entry == "Fizz" || entry == "FizzBuzz");
        bool is_a_multiple = (num % a == 0);

        if (required_a_multiple != is_a_multiple) {
            return false;
        }
    }

    return true;
}

bool check_b(long long b, int c, int d, const vector<string>& transcript) {
    if (b <= 0) return false;

    for (int i = 0; i <= d - c; ++i) {
        long long num = (long long)c + i;
        const string& entry = transcript[i];

        bool required_b_multiple = (entry == "Buzz" || entry == "FizzBuzz");
        bool is_b_multiple = (num % b == 0);

        if (required_b_multiple != is_b_multiple) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, d;
    cin >> c >> d;

    int n = d - c + 1;
    vector<string> transcript(n);
    for (int i = 0; i < n; ++i) {
        cin >> transcript[i];
    }

    long long found_a = -1;

    for (long long a = 1; a <= d + 1; ++a) {
        if (check_a(a, c, d, transcript)) {
            found_a = a;
            break;
        }
    }

    long long found_b = -1;
    for (long long b = 1; b <= d + 1; ++b) {
        if (check_b(b, c, d, transcript)) {
            found_b = b;
            break;
        }
    }

    cout << found_a << " " << found_b << endl;
    return 0;
}