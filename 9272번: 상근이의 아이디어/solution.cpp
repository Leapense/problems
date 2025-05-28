#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    if (!(cin >> n1 >> n2)) {
        return 1;
    }

    long long k = static_cast<long long>(n2) - n1 + 1;
    long long result = k * (k - 1) / 2;
    cout << result << "\n";
    return 0;
}