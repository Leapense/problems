#include <bits/stdc++.h>
using namespace std;

int count_p_in_factorial(int n, int p) {
    int count = 0;
    long long power = p;
    while (power <= n) {
        count += n / power;
        power *= p;
    }

    return count;
}

int find_trailing_zeros_in_combination(int N, int K) {
    int count2 = count_p_in_factorial(N, 2) - count_p_in_factorial(K, 2) - count_p_in_factorial(N - K, 2);
    int count5 = count_p_in_factorial(N, 5) - count_p_in_factorial(K, 5) - count_p_in_factorial(N - K, 5);

    return min(count2, count5);
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int N, K;
    cin >> N >> K;

    cout << find_trailing_zeros_in_combination(N, K) << endl;

    return 0;
}