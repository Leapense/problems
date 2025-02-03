#include <bits/stdc++.h>
using namespace std;

class MagicRitual
{
public:
    vector<int> digits;
    const int Tmap[10] = {0, 1, 1, 3, 2, 1, 3, 7, 4, 9};
    const int Fsingle[10] = {0, 1, 1, 3, 1, 1, 3, 7, 1, 9};

    MagicRitual(const string &s)
    {
        for (char c : s)
            digits.push_back(c - '0');
    }

    void addSmall(int addVal)
    {
        int i = digits.size() - 1;
        int sum = digits[i] + addVal;
        if (sum < 10)
        {
            digits[i] = sum;
            return;
        }
        digits[i] = sum % 10;
        int carry = sum / 10;
        i--;

        while (i >= 0 && carry)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
                carry = 1;
                i--;
                continue;
            }
            int s = digits[i] + carry;
            digits[i] = s % 10;
            carry = s / 10;
            i--;
        }

        if (carry)
            digits.insert(digits.begin(), carry);
    }

    void process()
    {
        while (digits.size() > 1)
        {
            int d = digits.back();
            int addVal = Tmap[d];
            digits.pop_back();
            if (addVal > 0)
                addSmall(addVal);
        }
    }

    int finalMagic()
    {
        int d = digits[0];
        while (d != 1 && d != 3 && d != 7 && d != 9)
        {
            int last = d % 10;
            d = (d / 10) + Tmap[last];
        }

        return d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        MagicRitual ritual(s);
        ritual.process();
        cout << ritual.finalMagic() << "\n";
    }

    return 0;
}