#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    unsigned long long N;
    cin >> N;

    unsigned long long half = N / 2;
    __int128 ans;

    if (N % 2 == 0)
    {
        ans = (__int128)half * half;
    }
    else
    {
        ans = (__int128)half * (half + 1);
    }

    if (ans == 0)
    {
        cout << 0;
        return 0;
    }

    string s;
    while (ans > 0)
    {
        int digit = (int)(ans % 10);
        s.push_back('0' + digit);
        ans /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}