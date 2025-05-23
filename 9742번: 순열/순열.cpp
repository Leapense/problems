#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long k;

    while (cin >> s >> k) {
        int n = s.size();
        long long total = 1;

        for (int i = 2; i <= n; i++) total *= i;
        if (k > total) {
            cout << s << " " << k << " = " << "No permutation" << "\n";
            continue; 
        }

        string original = s;
        sort(original.begin(), original.end());
        string result = "";
        long long kk = k - 1;
        vector<int> factorial(n, 1);

        for (int i = 1; i < n; i++) factorial[i] = factorial[i - 1] * i;

        string temp = original;

        for (int i = n - 1; i >= 0; i--) {
            long long idx = kk / factorial[i];
            if (idx >= temp.size()) {
                result = "No permutation";
                break;
            }
            result += temp[idx];
            temp.erase(temp.begin() + idx);
            kk %= factorial[i];
        }

        cout << s << " " << k << " = " << (result.empty() ? "No permutation" : result) << "\n";
    }

    return 0;
}