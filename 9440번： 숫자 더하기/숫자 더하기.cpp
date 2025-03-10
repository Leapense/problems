#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> digits(n);
        for (int i = 0; i < n; i++)
        {
            cin >> digits[i];
        }
        sort(digits.begin(), digits.end());
        string a = "", b = "";
        int idxA = -1, idxB = -1;
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] != 0)
            {
                a.push_back('0' + digits[i]);
                idxA = i;
                break;
            }
        }
        if (idxA != -1)
            digits.erase(digits.begin() + idxA);
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] != 0)
            {
                b.push_back('0' + digits[i]);
                idxB = i;
                break;
            }
        }
        if (idxB != -1)
            digits.erase(digits.begin() + idxB);
        bool turn = true;
        for (auto d : digits)
        {
            if (turn)
                a.push_back('0' + d);
            else
                b.push_back('0' + d);
            turn = !turn;
        }
        long long numA = stoll(a);
        long long numB = stoll(b);
        cout << numA + numB << "\n";
    }
    return 0;
}
