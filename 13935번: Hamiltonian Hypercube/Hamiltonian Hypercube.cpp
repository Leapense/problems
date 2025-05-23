#include <bits/stdc++.h>

using namespace std;

unsigned long long grayToBinary(const string &gray)
{
    int prev = gray[0] - '0';
    unsigned long long binary = prev;

    for (size_t i = 1; i < gray.size(); ++i)
    {
        int currentGray = gray[i] - '0';
        int currentBinary = prev ^ currentGray;
        binary = (binary << 1) | currentBinary;
        prev = currentBinary;
    }

    return binary;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string a, b;

    cin >> n >> a >> b;

    unsigned long long ia = grayToBinary(a);
    unsigned long long ib = grayToBinary(b);

    unsigned long long res = ib - ia - 1;

    cout << res << "\n";

    return 0;
}