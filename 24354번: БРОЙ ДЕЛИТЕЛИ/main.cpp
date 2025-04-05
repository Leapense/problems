#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> divisors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }

    int bestNumber = 1;
    int maxDivCount = divisors[1];

    for (int i = 2; i <= n; i++) {
        if (divisors[i] > maxDivCount) {
            maxDivCount = divisors[i];
            bestNumber = i;
        }
    }

    cout << bestNumber << "\n" << maxDivCount << "\n";
    return 0;
}
