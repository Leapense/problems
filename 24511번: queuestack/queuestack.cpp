#include <bits/stdc++.h>
using namespace std;

class Queuestack
{
public:
    int N, M;
    vector<int> A, B, C, queues;
    Queuestack(int n, vector<int> a, vector<int> b)
    {
        N = n;
        A = a;
        B = b;
        for (int i = 0; i < N; i++)
            if (A[i] == 0)
                queues.push_back(B[i]);
        reverse(queues.begin(), queues.end());
    }

    void process(int m, vector<int> c)
    {
        M = m;
        C = c;
        int k = queues.size();
        string res = "";

        for (int j = 1; j <= M; j++)
        {
            if (j <= k)
            {
                res += to_string(queues[j - 1]) + " ";
            }
            else
            {
                res += to_string(C[j - k - 1]) + " ";
            }
        }

        if (!res.empty())
            res.pop_back();
        cout << res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &x : A)
        cin >> x;

    vector<int> B(N);
    for (auto &x : B)
        cin >> x;

    Queuestack qs(N, A, B);

    int M;
    cin >> M;

    vector<int> C(M);
    for (auto &x : C)
        cin >> x;
    qs.process(M, C);
}