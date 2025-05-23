#include <bits/stdc++.h>
using namespace std;

const int segments[10] = {6,2,5,5,4,5,6,3,7,6};

int calculate_current(int num) {
    int abs_num = abs(num);
    int current = 0;

    if (num < 0) {
        current += 5;
    }

    if (abs_num == 0) {
        current += segments[0] * 5;
        return current;
    }

    vector<int> digits;

    while(abs_num > 0) {
        digits.push_back(abs_num % 10);
        abs_num /= 10;
    }

    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        current += segments[*it] * 5;
    }

    return current;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, vector<int>> current_to_numbers;
    for (int num = -999; num <= 999; ++num) {
        string s = to_string(num);
        bool valid = true;

        if (s.length() > 1 && s[0] == '0') continue;
        if (s.length() > 2 && s[0] == '-' && s[1] == '0') continue;

        int current = calculate_current(num);
        current_to_numbers[current].push_back(num);
    }

    int X_in, Y_in, Z_in;

    while(cin >> X_in) {
        if(X_in == 0) break;
        cin >> Y_in >> Z_in;
        vector<int> Xs, Ys, Zs;

        if (current_to_numbers.find(X_in) != current_to_numbers.end()) {
            Xs = current_to_numbers[X_in];
        }
        if (current_to_numbers.find(Y_in) != current_to_numbers.end()) {
            Ys = current_to_numbers[Y_in];
        }
        if (current_to_numbers.find(Z_in) != current_to_numbers.end()) {
            Zs = current_to_numbers[Z_in];
        }

        int count = 0;

        for (auto X : Xs) {
            for (auto Y : Ys) {
                long long res = (long long)X + Y;
                if (res >= -999 && res <= 999 && find(Zs.begin(), Zs.end(), (int)res) != Zs.end()) {
                    count++;
                }

                res = (long long)X - Y;
                if (res >= -999 && res <= 999 && find(Zs.begin(), Zs.end(), (int)res) != Zs.end()) {
                    count++;
                }

                res = (long long)X * Y;
                if (res >= -999 && res <= 999 && find(Zs.begin(), Zs.end(), (int)res) != Zs.end()) {
                    count++;
                }

                if (Y != 0) {
                    res = X / Y;
                    if (res >= -999 && res <= 999 && find(Zs.begin(), Zs.end(), (int)res) != Zs.end()) {
                        count++;
                    }
                }
            }
        }

        if (count == 0) {
            cout << "0 solutions for " << X_in << " " << Y_in << " " << Z_in << endl;
        } else if (count == 1) {
            cout << "1 solution for " << X_in << " " << Y_in << " " << Z_in << endl;
        } else {
            cout << count << " solutions for " << X_in << " " << Y_in << " " << Z_in << endl;
        }
    }

    return 0;
}