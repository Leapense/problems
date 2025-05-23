#include <bits/stdc++.h>
using namespace std;

string sortedDigits(const string &num)
{
    string sorted_num = num;
    sort(sorted_num.begin(), sorted_num.end());
    size_t non_zero = sorted_num.find_first_not_of('0');
    return non_zero != string::npos ? sorted_num.substr(non_zero) : "0";
}

string addReverse(const string &num)
{
    string rev_num = num;
    reverse(rev_num.begin(), rev_num.end());

    string sum;
    int carry = 0;
    for (int i = 0, n = num.size(); i < n || carry; ++i)
    {
        int digitSum = carry;
        if (i < num.size())
            digitSum += num[num.size() - 1 - i] - '0';
        if (i < rev_num.size())
            digitSum += rev_num[rev_num.size() - 1 - i] - '0';

        sum.push_back((digitSum % 10) + '0');
        carry = digitSum / 10;
    }

    reverse(sum.begin(), sum.end());
    return sortedDigits(sum);
}

bool isCreeper(const string &num)
{
    return regex_match(num, regex("1233+4444?")) || regex_match(num, regex("5566+7777?"));
}

void solve()
{
    int P;
    cin >> P;

    while (P--)
    {
        int K, M;
        string value;
        cin >> K >> M >> value;

        unordered_map<string, int> seen;
        bool found = false;

        for (int i = 1; i <= M; ++i)
        {
            if (isCreeper(value))
            {
                cout << K << " C " << i << '\n';
                found = true;
                break;
            }

            if (seen.count(value))
            {
                cout << K << " R " << i << '\n';
                found = true;
                break;
            }

            seen[value] = i;
            if (i != M)
                value = addReverse(value);
        }

        if (!found)
            cout << K << " " << value << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
