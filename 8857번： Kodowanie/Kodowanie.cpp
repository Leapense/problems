#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    static long long fib[46];
    fib[1] = 1; fib[2] = 1;
    for (int i = 3; i <= 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    while(T--) {
        int n;
        cin >> n;

        cout << fib[n] << "\n";
    }

    return 0;
}