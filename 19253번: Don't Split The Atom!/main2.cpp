#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

using namespace std;

void solve(istream &in, ostream &out)
{
    int t;
    in >> t;

    while (t--)
    {
        long long n;
        in >> n;

        out << (n % 2 == 0 ? "A" : "B") << "\n";
    }
}

#ifndef UNIT_TEST
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#else
void runTests()
{
    {
        string input = "1\n1\n";
        string expected = "B\n";
        stringstream ss(input), out;
        solve(ss, out);
        assert(out.str() == expected);
    }
    {
        string input = "1\n2\n";
        string expected = "A\n";
        stringstream ss(input), out;
        solve(ss, out);
        assert(out.str() == expected);
    }
    {
        string input = "1\n3\n";
        string expected = "B\n";
        stringstream ss(input), out;
        solve(ss, out);
        assert(out.str() == expected);
    }
    {
        string input = "3\n17\n100\n999999\n";
        string expected = "B\nA\nB\n";
        stringstream ss(input), out;
        solve(ss, out);
        assert(out.str() == expected);
    }

    cout << "모든 테스트들 성공적으로 통과되었습니다.\n";
}

int main()
{
    runTests();
    return 0;
}
#endif