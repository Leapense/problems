#include <iostream>
#include <string>
#include <array>

using namespace std;
constexpr int MOD = 11092019;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    array<int, 26> freq = {0};

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    long long result = 1;

    for (int count : freq)
    {
        result = (result * (1LL + count)) % MOD;
    }

    cout << result << "\n";

    return 0;
}