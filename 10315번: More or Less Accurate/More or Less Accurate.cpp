#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;

    while (getline(cin, s))
    {
        if (s == "")
            continue;
        int n = s.size();
        vector<int> res;

        int carry = 1;
        for (int i = n - 1; i >= 0 || carry != 0; i--)
        {
            int digit = (i >= 0 ? s[i] - '0' : 0);
            int sum = digit + carry;
            int new_digit = ((sum % 2) + 2) % 2;
            carry = -(sum - new_digit) / 2;
            res.push_back(new_digit);
        }

        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        for (auto it = res.rbegin(); it != res.rend(); it++)
        {
            cout << *it;
        }
        cout << "\n";
    }

    return 0;
}