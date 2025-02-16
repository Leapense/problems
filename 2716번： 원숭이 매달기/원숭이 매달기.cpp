#include <iostream>
#include <string>
#include <numeric>

using namespace std;
typedef long long ll;
string s;
int idx;

ll parse()
{
    if (idx >= s.size() || s[idx] == ']')
        return 1;
    idx++;
    ll left = parse();
    ll right = parse();
    idx++;
    ll g = gcd(left, right);
    ll l = (left / g) * right;
    return 2 * l;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        getline(cin, s);
        if (s == "")
        {
            cout << 1 << "\n";
            continue;
        }
        idx = 0;
        cout << parse() << "\n";
    }

    return 0;
}