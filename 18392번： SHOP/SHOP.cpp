#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct Bill {
    long long value;
    long long count;
};

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;

    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        long long M;
        cin >> M;
        string bill_input;
        cin >> bill_input;

        vector<string> bill_parts = split(bill_input, ',');
        vector<Bill> bills;

        for (auto &part : bill_parts) {
            size_t colon_pos = part.find(':');
            if (colon_pos != string::npos) {
                string m_str = part.substr(0, colon_pos);
                string a_str = part.substr(colon_pos + 1);
                long long m = stoll(m_str);
                long long a = stoll(a_str);
                bills.push_back(Bill{m, a});
            }
        }

        sort(bills.begin(), bills.end(), [&](const Bill &a, const Bill &b) -> bool {
            return a.value > b.value;
        });

        long long remaining = M;
        vector<pair<long long, long long>> used_bills;
        for (auto &bill : bills) {
            if (remaining <= 0) break;
            long long use = min(remaining / bill.value, bill.count);

            if (use > 0) {
                used_bills.emplace_back(bill.value, use);
                remaining -= bill.value * use;
            }
        }

        cout << "Customer" << test_case << ":\n";
        if (remaining == 0) {
            for (auto &p : used_bills) {
                cout << p.first << " " << p.second << "\n";
            }
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}