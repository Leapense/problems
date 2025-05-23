#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>
#include <cassert>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<bitset<128>> v(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a)
                v[i].set(j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            bitset<128> diff1 = v[i] & ~v[i];
            bitset<128> diff2 = v[j] & ~v[j];
            if (diff1.any() && diff2.any())
            {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES";
}

void run_tests()
{
    struct Test
    {
        string input;
        string expected;
    };

    vector<Test> tests = {
        {"1 1\n1\n", "YES"},
        {"1 1\n0\n", "YES"},
        {"2 2\n1 1\n1 0\n", "YES"},
        {"2 2\n1 0\n0 1\n", "NO"},
        {"3 3\n1 1 1\n1 0 0\n1 1 0\n", "YES"},
        {"3 3\n1 0 1\n1 1 0\n0 1 1\n", "NO"}};

    for (auto &test : tests)
    {
        istringstream iss(test.input);
        ostringstream oss;
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        cin.rdbuf(iss.rdbuf());
        cout.rdbuf(oss.rdbuf());
        solve();
        cout.rdbuf(coutbuf);
        cin.rdbuf(cinbuf);
        string output = oss.str();

        if (output == test.expected)
        {
            cout << "Test passed.\n";
        }
        else
        {
            cout << "Test failed.\nInput:\n"
                 << test.input << "\nExpected:\n"
                 << test.expected << "\nGot:\n"
                 << output << "\n";
        }
    }
}

int main()
{
    run_tests();
    return 0;
}