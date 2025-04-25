#include <bits/stdc++.h>
using namespace std;

struct FastReader
{
    static const int BUF = 1 << 20;
    int idx, sz;
    char buf[BUF];
    FastReader() : idx(0), sz(0) {}
    inline char read()
    {
        if (idx >= sz)
        {
            sz = fread(buf, 1, BUF, stdin);
            idx = 0;
            if (sz == 0)
                return EOF;
        }
        return buf[idx++];
    }

    bool skip()
    {
        char c;
        do
        {
            c = read();
            if (c == EOF)
                return false;
        } while (c <= ' ');
        idx--;
        return true;
    }

    bool readInt(int &x)
    {
        if (!skip())
            return false;
        char c = read();
        bool neg = false;
        if (c == '-')
        {
            neg = true;
            c = read();
        }
        long long v = 0;
        while ('0' <= c && c <= '9')
        {
            v = v * 10 + (c - '0');
            c = read();
        }

        x = neg ? -v : v;
        return true;
    }

    bool readLongLong(long long &x)
    {
        if (!skip())
            return false;
        char c = read();
        bool neg = false;
        if (c == '-')
        {
            neg = true;
            c = read();
        }
        long long v = 0;
        while ('0' <= c && c <= '9')
        {
            v = v * 10 + (c - '0');
            c = read();
        }

        x = neg ? -v : v;
        return true;
    }
};

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FastReader fr;
    int N;
    fr.readInt(N);
    vector<long long> l(N);
    for (int i = 0; i < N; i++)
    {
        fr.readLongLong(l[i]);
    }

    long long L;
    fr.readLongLong(L);

    vector<long long> pre(N + 1);
    for (int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + l[i - 1];
    long long total = pre[N];
    long long max_scroll2 = (total > L ? 2 * (total - L) : 0);

    int Q;
    fr.readInt(Q);
    cout << fixed << setprecision(2);

    while (Q--)
    {
        int idx;
        fr.readInt(idx);
        long long center2 = 2 * pre[idx - 1] + l[idx - 1];
        long long x2 = center2 - L;
        if (x2 < 0)
            x2 = 0;
        if (x2 > max_scroll2)
            x2 = max_scroll2;

        long long hund = x2 * 50;
        long long ip = hund / 100;
        long long fp = hund % 100;

        cout << ip << '.' << setw(2) << setfill('0') << fp << '\n';
    }
    return 0;
}
#else
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FastReader fr;
    int N;
    fr.readInt(N);
    vector<long long> l(N);
    for (int i = 0; i < N; i++)
    {
        fr.readLongLong(l[i]);
    }

    long long L;
    fr.readLongLong(L);

    vector<long long> pre(N + 1);
    for (int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + l[i - 1];
    long long total = pre[N];
    long long max_scroll2 = (total > L ? 2 * (total - L) : 0);

    int Q;
    fr.readInt(Q);
    cout << fixed << setprecision(2);

    while (Q--)
    {
        int idx;
        fr.readInt(idx);
        long long center2 = 2 * pre[idx - 1] + l[idx - 1];
        long long x2 = center2 - L;
        if (x2 < 0)
            x2 = 0;
        if (x2 > max_scroll2)
            x2 = max_scroll2;

        long long hund = x2 * 50;
        long long ip = hund / 100;
        long long fp = hund % 100;

        cout << ip << '.' << setw(2) << setfill('0') << fp << '\n';
    }
}
#endif