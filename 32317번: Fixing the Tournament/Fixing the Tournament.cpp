#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    int total = 1 << n;
    int value = total - r + 1;
    int k = floor(log2(value));
    cout << k + 1 << endl;

    return 0;
}