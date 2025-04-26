#include <bits/stdc++.h>
using namespace std;

void solve(istream &in, ostream &out)
{
    ios::sync_with_stdio(false);
    in.tie(nullptr);
    int N;
    in >> N;
    unordered_map<long long, int> cnt;
    cnt.reserve(N * 2);
    for (int i = 0; i < N; ++i)
    {
        long long x;
        in >> x;
        cnt[x]++;
    }
    int Q;
    in >> Q;
    for (int qi = 0; qi < Q; ++qi)
    {
        int a;
        in >> a;
        vector<long long> A(a);
        for (int i = 0; i < a; ++i)
            in >> A[i];
        int b;
        in >> b;
        vector<long long> B(b);
        for (int i = 0; i < b; ++i)
            in >> B[i];

        bool ok = true;
        if (a)
        {
            unordered_map<long long, int> need;
            need.reserve(a * 2);
            for (long long c : A)
                need[c]++;
            for (auto &p : need)
            {
                auto it = cnt.find(p.first);
                if (it == cnt.end() || it->second < p.second)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                for (auto &p : need)
                {
                    auto &v = cnt[p.first];
                    v -= p.second;
                    if (v == 0)
                        cnt.erase(p.first);
                }
            }
        }
        if (ok)
        {
            for (long long c : B)
                cnt[c]++;
        }
    }
    long long M = 0;
    for (auto &p : cnt)
        M += p.second;
    out << M << "\n";
    if (M)
    {
        bool first = true;
        for (auto &p : cnt)
        {
            for (int i = 0; i < p.second; ++i)
            {
                if (!first)
                    out << ' ';
                out << p.first;
                first = false;
            }
        }
        out << "\n";
    }
}

int main()
{
    solve(cin, cout);
    return 0;
}