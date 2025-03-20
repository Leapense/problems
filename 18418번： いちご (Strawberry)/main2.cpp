#include <bits/stdc++.h>
using namespace std;

void solve(istream &in, ostream &out)
{
    long long N;
    in >> N;
    vector<long long> A(N), T(N);
    long long M = 0;
    for (long long i = 0; i < N; i++)
    {
        in >> A[i] >> T[i];
        M = max(M, A[i]);
    }
    long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        long long outward = max(2LL * M, T[i] + 2LL * M - A[i]);
        long long inbound = max(2LL * M, T[i] + A[i]);
        ans = max(ans, min(outward, inbound));
    }
    out << ans << "\n";
}

bool runTest(const string &inputData, const string &expectedOutput)
{
    istringstream in(inputData);
    ostringstream out;
    solve(in, out);
    return out.str() == (expectedOutput + "\n");
}

int main()
{
    vector<pair<string, string>> tests = {
        {"1\n0 0\n", "0"},
        {"1\n10 0\n", "20"},
        {"1\n10 10\n", "20"},
        {"2\n1 10\n2 10\n", "12"},
        {"10\n1 3\n2 1\n3 4\n4 1\n5 5\n6 9\n7 2\n8 6\n9 5\n10 3\n", "20"},
        {"10\n0 450\n5 445\n10 430\n15 405\n20 370\n25 325\n30 270\n35 205\n40 130\n45 45\n", "450"},
        {"15\n11 23\n3 94\n89 3\n38 58\n65 29\n41 3\n80 42\n22 76\n48 85\n83 98\n87 29\n97 96\n22 75\n57 25\n99 33\n", "198"},
        {"5\n0 5\n10 0\n25 50\n25 0\n1 1\n", "75"}};

    for (int i = 0; i < (int)tests.size(); i++)
    {
        bool ok = runTest(tests[i].first, tests[i].second);
        cout << "Test " << i + 1 << " : " << (ok ? "PASSED" : "FAILED") << "\n";
    }
    return 0;
}
