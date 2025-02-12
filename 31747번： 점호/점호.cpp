#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Fenw
{
    int n;
    vector<int> fenw;
    Fenw(int n) : n(n)
    {
        fenw.assign(n + 1, 0);
    }
    void init(vector<int> &arr)
    {
        for (int i = 1; i <= n; i++)
        {
            fenw[i] += arr[i];
            int j = i + (i & -i);
            if (j <= n)
                fenw[j] += fenw[i];
        }
    }
    void update(int i, int delta)
    {
        while (i <= n)
        {
            fenw[i] += delta;
            i += i & -i;
        }
    }
    int query(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += fenw[i];
            i -= i & -i;
        }
        return s;
    }
    int findKth(int k)
    {
        int idx = 0;
        int bitMask = 1 << 17;
        while (bitMask)
        {
            int tIdx = idx + bitMask;
            if (tIdx <= n && fenw[tIdx] < k)
            {
                k -= fenw[tIdx];
                idx = tIdx;
            }
            bitMask >>= 1;
        }
        return idx + 1;
    }
};

struct SegTree
{
    int n;
    vector<int> tree;
    SegTree(int n) : n(n)
    {
        tree.assign(4 * n, INF);
    }
    void build(vector<int> &arr, int idx, int l, int r)
    {
        if (l == r)
        {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
    int query(int idx, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return INF;
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        int leftMin = query(idx * 2, l, mid, ql, qr);
        int rightMin = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return min(leftMin, rightMin);
    }
    void update(int idx, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    vector<int> initArr(N + 1, 1);
    Fenw fenw(N);
    fenw.init(initArr);

    vector<int> grade1Arr(N + 1, INF), grade2Arr(N + 1, INF);
    for (int i = 1; i <= N; i++)
    {
        if (A[i] == 1)
            grade1Arr[i] = i;
        else if (A[i] == 2)
            grade2Arr[i] = i;
    }
    SegTree seg1(N), seg2(N);
    seg1.build(grade1Arr, 1, 1, N);
    seg2.build(grade2Arr, 1, 1, N);

    int timeSteps = 0;
    int remaining = N;
    while (remaining > 0)
    {
        int p = fenw.query(N);
        int m = min(K, p);
        int pos = fenw.findKth(m);

        int candidate1 = seg1.query(1, 1, N, 1, pos);
        int candidate2 = seg2.query(1, 1, N, 1, pos);

        if (candidate1 != INF && candidate2 != INF)
        {
            fenw.update(candidate1, -1);
            fenw.update(candidate2, -1);
            seg1.update(1, 1, N, candidate1, INF);
            seg2.update(1, 1, N, candidate1, INF);
            seg1.update(1, 1, N, candidate2, INF);
            seg2.update(1, 1, N, candidate2, INF);
            remaining -= 2;
        }
        else if (candidate1 != INF)
        {
            fenw.update(candidate1, -1);
            seg1.update(1, 1, N, candidate1, INF);
            seg2.update(1, 1, N, candidate1, INF);
            remaining -= 1;
        }
        else if (candidate2 != INF)
        {
            fenw.update(candidate2, -1);
            seg1.update(1, 1, N, candidate2, INF);
            seg2.update(1, 1, N, candidate2, INF);
            remaining -= 1;
        }
        timeSteps++;
    }

    cout << timeSteps << "\n";
    return 0;
}
