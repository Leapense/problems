#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, int>> prefixes = {
        {"centi", -2},
        {"milli", -3},
        {"micro", -6},
        {"mega", 6},
        {"giga", 9},
        {"kilo", 3},
        {"deci", -1},
        {"nano", -9},
        {"tera", 12}
    };

    string s;
    cin >> s;

    int n = s.size();
    int pos = 0;

    long long total_prefix_exponent = 0;
    int k = 1;

    while (pos < n) {
        bool matched = false;

        for (auto &[prefix, exp] : prefixes) {
            int len = prefix.size();
            if (pos + len <= n && s.substr(pos, len) == prefix) {
                total_prefix_exponent += exp;
                pos += len;
                matched = true;
                break;
            }
        }

        if (matched) {
            continue;
        }

        string meter = "meter";
        int len_meter = 5;

        if (pos + len_meter <= n && s.substr(pos, len_meter) == meter) {
            pos += len_meter;

            if (pos < n && s[pos] == '^') {
                if (pos + 1 < n && (s[pos + 1] == '2' || s[pos + 1] == '3')) {
                    k = s[pos + 1] - '0';
                    pos += 2;
                } else {
                    k = 1;
                    pos += 1;
                }
            } else {
                k = 1;
            }

            break;
        } else {
            break;
        }
    }

    long long x = total_prefix_exponent * (long long)k;
    cout << x << endl;

    return 0;
}