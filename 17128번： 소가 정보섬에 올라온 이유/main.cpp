#include <iostream>
#include <vector>

using ll = long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    ll S = 0;

    for (int i = 0; i < N; i++)
    {
        ll prod = A[i] * A[(i + 1) % N] * A[(i + 2) % N] * A[(i + 3) % N];
        S += prod;
    }

    while (Q--)
    {
        int idx;
        std::cin >> idx;
        idx--;

        ll sumAffected = 0;

        for (int j = 0; j < 4; j++)
        {
            int start = (idx - j + N) % N;
            ll prod = A[start] * A[(start + 1) % N] * A[(start + 2) % N] * A[(start + 3) % N];
            sumAffected += prod;
        }

        S += -2 * sumAffected;

        A[idx] = -A[idx];

        std::cout << S << "\n";
    }

    return 0;
}