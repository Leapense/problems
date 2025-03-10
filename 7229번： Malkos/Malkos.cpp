#include <bits/stdc++.h>
using namespace std;

struct Fenw
{
    int n;
    vector<int> fenw;
    Fenw(int n) : n(n), fenw(n + 1, 0) {}
    void update(int i, int delta)
    {
        for (; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    int query(int i)
    {
        int s = 0;
        for (; i; i -= i & -i)
            s += fenw[i];
        return s;
    }
    int total()
    {
        return query(n);
    }
    int findKth(int k)
    {
        int pos = 0;
        for (int bit = 1 << 20; bit; bit >>= 1)
        {
            int next = pos + bit;
            if (next <= n && fenw[next] < k)
            {
                k -= fenw[next];
                pos = next;
            }
        }

        return pos + 1;
    }
    int getMin()
    {
        if (total() == 0)
            return -1;
        return findKth(1);
    }
    int getMax()
    {
        int tot = total();
        if (tot == 0)
            return -1;
        return findKth(tot);
    }
    int getMaxLE(int X)
    {
        if (X < 1)
            return -1;
        int cnt = query(X);
        if (cnt == 0)
            return -1;
        return findKth(cnt);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    const int MAXV = 1000000;

    vector<int> logs(N);
    for (int i = 0; i < N; i++)
    {
        cin >> logs[i];
    }

    vector<int> freq(MAXV + 1, 0);
    for (auto &x : logs)
    {
        freq[x]++;
    }

    Fenw fenw(MAXV);
    for (int i = 1; i <= MAXV; i++)
    {
        if (freq[i])
            fenw.update(i, freq[i]);
    }

    int height = 0;
    int capacity = 0;

    while (fenw.total() > 0)
    {
        if (height == 0)
        {
            int x = fenw.getMax();
            fenw.update(x, -1);
            height++;
            capacity = x;
        }
        else
        {
            int tot = fenw.total();
            int use = min(capacity, tot);
            for (int i = 0; i < use; i++)
            {
                int y = fenw.getMin();
                fenw.update(y, -1);
            }
            height++;
            if (fenw.total() == 0)
                break;
            int candidate = fenw.getMaxLE(use);

            if (candidate == -1)
                break;
            fenw.update(candidate, -1);
            height++;
            capacity = candidate;
        }
    }

    cout << height << "\n";

    return 0;
}