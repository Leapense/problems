#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<string> binaries;
    for (int i = 0; i < (1 << N); i++)
    {
        string bin;
        for (int j = N - 1; j >= 0; j--)
        {
            bin.push_back((i & (1 << j)) ? '1' : '0');
        }

        binaries.push_back(bin);
    }

    sort(binaries.begin(), binaries.end(), [&](const string &a, const string &b)
         {
        int cntA = count(a.begin(), a.end(), '1');
        int cntB = count(b.begin(), b.end(), '1');

        if (cntA != cntB) return cntA < cntB;

        string ra = a, rb = b;
        reverse(ra.begin(), ra.end());
        reverse(rb.begin(), rb.end());

        return ra < rb; });

    for (int i = 0; i < binaries.size(); i++)
    {
        if (binaries[i] == S)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}