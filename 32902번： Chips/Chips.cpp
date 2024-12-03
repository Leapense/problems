#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    int min_m = n + 1;
    int max_m = k * n + 1;

    cout << min_m << " " << max_m << "\n";

    return 0;
}