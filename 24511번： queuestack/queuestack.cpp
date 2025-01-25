#include <bits/stdc++.h>
using namespace std;

class Queuestack
{
private:
    int n;
    vector<int> t;
    vector<long long> b;

public:
    Queuestack(int n, const vector<int> &t, const vector<long long> &b)
    {
        this->n = n;
        this->t = t;
        this->b = b;
    }
    long long process(long long x)
    {
        for (int i = 0; i < n; i++)
        {
            if (t[i] == 0)
            {
                long long tmp = b[i];
                b[i] = x;
                x = tmp;
            }
        }

        return x;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<long long> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int M;
    cin >> M;

    vector<long long> C(M);
    for (int i = 0; i < M; i++)
        cin >> C[i];

    Queuestack qs(N, A, B);
    for (int i = 0; i < M; i++)
    {
        cout << qs.process(C[i]) << (i + 1 < M ? ' ' : '\n');
    }

    return 0;
}