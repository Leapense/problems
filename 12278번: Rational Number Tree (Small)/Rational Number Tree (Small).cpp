#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int caseNo = 1; caseNo <= T; ++caseNo)
    {
        int problem;
        cin >> problem;

        if (problem == 1)
        {
            unsigned int n;
            cin >> n;
            unsigned int p = 1, q = 1;
            string bin;
            unsigned int temp = n;

            while (temp > 0)
            {
                bin.push_back((temp % 2) + '0');
                temp /= 2;
            }

            reverse(bin.begin(), bin.end());
            for (size_t i = 1; i < bin.size(); ++i)
            {
                if (bin[i] == '0')
                {
                    q = p + q;
                }
                else
                {
                    p = p + q;
                }
            }

            cout << "Case #" << caseNo << ": " << p << " " << q;
        }
        else if (problem == 2)
        {
            unsigned int p, q;
            cin >> p >> q;

            string code;
            while (!(p == 1 && q == 1))
            {
                if (p < q)
                {
                    code.push_back('0');
                    q -= p;
                }
                else
                {
                    code.push_back('1');
                    p -= q;
                }
            }

            reverse(code.begin(), code.end());
            string bin = "1" + code;
            unsigned int n = 0;

            for (char c : bin)
            {
                n = (n << 1) + (c - '0');
            }

            cout << "Case #" << caseNo << ": " << n;
        }

        cout << "\n";
    }

    return 0;
}