#include <iostream>
using namespace std;

int main()
{
    long long l, r, a;
    cin >> l >> r >> a;

    long long T = r - l + 1;
    long long n = (r - l) / a;
    long long result = n * T - a * (n * (n + 1) / 2);

    cout << result << endl;

    return 0;
}