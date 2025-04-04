#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int total = 3 * N;
    vector<long long> age(total);

    for (int i = 0; i < total; i++) {
        cin >> age[i];
    }

    sort(age.begin(), age.end());

    long long answer = age[2 * N - 1] - age[N];

    cout << answer << "\n";
    return 0;
}
