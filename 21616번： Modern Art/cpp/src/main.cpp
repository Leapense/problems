#include "main.h"
#include <vector>
using namespace std;

void solve(std::istream &in, std::ostream &out)
{
    int M, N, K;
    in >> M >> N >> K;
    vector<int> rows(M, 0), cols(N, 0);
    for (int i = 0; i < K; i++)
    {
        char type;
        int idx;
        in >> type >> idx;
        if (type == 'R')
        {
            rows[idx - 1] ^= 1;
        }
        else
        {
            cols[idx - 1] ^= 1;
        }
    }

    ll rOdd = 0;
    for (int r : rows)
    {
        rOdd += r;
    }
    ll cOdd = 0;
    for (int c : cols)
    {
        cOdd += c;
    }

    ll ans = rOdd * (N - cOdd) + (M - rOdd) * cOdd;
    out << ans;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(std::cin, std::cout);
    return 0;
}
#endif