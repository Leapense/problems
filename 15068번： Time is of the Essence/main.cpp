#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    istringstream iss(line);

    int n;
    iss >> n;

    vector<string> names(n);
    vector<long long> conv(n - 1);
    iss >> names[0];

    for (int i = 0; i < n - 1; i++)
    {
        iss >> conv[i] >> names[i + 1];
    }

    long long m;
    cin >> m;

    long long total = 1;
    vector<long long> factor(n);

    factor[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        factor[i] = conv[i] * factor[i + 1];
    }

    double topVal = (double)m / factor[0];
    long long roundedTop = (long long)round(topVal);

    cout << roundedTop << " " << names[0] << "\n";

    long long whole = m / factor[0];
    long long remainder = m - whole * factor[0];
    double secondVal = (double)remainder / (factor[0] / conv[0]);
    long long roundedSecond = (long long)round(secondVal);
    if (roundedSecond == conv[0])
    {
        whole++;
        roundedSecond = 0;
    }

    cout << whole << " " << names[0] << " " << roundedSecond << " " << names[1] << "\n";
    return 0;
}