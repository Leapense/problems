#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;
        
        int len = s.length();

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int odd = 0;

        for (auto &[c, count] : freq) {
            if (count % 2 != 0) {
                odd++;
            }
        }
        if (odd > 1) {
            cout << "Impossible\n";
            continue;
        }

        vector<char> chars(s.begin(), s.end());
        int swaps = 0;

        bool impossible = false;

        int i = 0, j = len - 1;
        while (i < j) {
            if (chars[i] == chars[j]) {
                i++;
                j--;
                continue;
            }

            int k = j;

            while (k > i && chars[k] != chars[i]) {
                k--;
            }
            if (k == i) {
                k = i;
                while (k < j && chars[k] != chars[j]) {
                    k++;
                }

                if (k == j) {
                    swap(chars[i], chars[i + 1]);
                    swaps++;
                    continue;
                } else {
                    while(k > i) {
                        swap(chars[k], chars[k - 1]);
                        swaps++;
                        k--;
                    }

                    i++;
                    j--;
                }
            } else {
                while (k < j) {
                    swap(chars[k], chars[k + 1]);
                    swaps++;
                    k++;
                }

                i++;
                j--;
            }
        }

        bool is_palindrome = true;
        for (int x = 0; x < len / 2; x++) {
            if (chars[x] != chars[len - x - 1]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            cout << swaps << "\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}