#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    long long total_score = 0;
    int c1 = 0, c2 = 0;

    for (size_t t = 0; t < s.length(); ++t) {
        if (s[t] == '1') {
            c1++;
        } else if (s[t] == '2') {
            c2++;
        }
        int m = min(c1, n);

        int r = n - m;
        int num2 = min(c2, r / 2);
        int total_power_plants = m + num2;

        total_score += total_power_plants;
    }

    cout << total_score << "\n";

    return 0;
}