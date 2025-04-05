#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long lcm_value = A[0];
    for (int i = 1; i < N; i++) {
        lcm_value = std::lcm(lcm_value, (long long)A[i]);
    }

    long long password = lcm_value - K;

    cout << password << "\n";
    return 0;
}
