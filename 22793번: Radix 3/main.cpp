#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string toGSC(long long n) {
    if (n == 0) return "0";

    string result = "";
    while (n != 0) {
        int rem = n % 3;
        n /= 3;

        if (rem == 2 || rem == -2) {
            if (rem == 2) {
                rem = -1;
                n += 1;
            } else {
                rem = 1;
                n -= 1;
            }
        }

        if (rem == 1) result.push_back('1');
        else if (rem == 0) result.push_back('0');
        else if (rem == -1) result.push_back('-');
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    long long num;
    while (cin >> num) {
        cout << num << " = " << toGSC(num) << " GSC" << "\n";
    }

    return 0;
}
