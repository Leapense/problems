#include <bits/stdc++.h>
using namespace std;

bool contains_pattern(const string& s, const string& p) {
    if (p.empty()) return false;
    if (p.length() > s.length()) return false;
    size_t len_s = s.length();
    size_t len_p = p.length();
    for (size_t i = 0; i <= len_s - len_p; ++i) {
        bool match = true;
        for (size_t j = 0; j < len_p; ++j) {
            if (p[j] != '.' && p[j] != s[i + j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<string> all_ips;
    all_ips.reserve(N);
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        all_ips.push_back(s);
    }

    vector<string> unique_ips;
    unique_ips.reserve(2000);
    unordered_set<string> seen;
    seen.reserve(2000);
    for (int i = 0; i < N; i++) {
        if (seen.find(all_ips[i]) == seen.end()) {
            unique_ips.push_back(all_ips[i]);
            seen.insert(all_ips[i]);
        }
    }

    string file_content = "";
    vector<string> skipped_ips;
    skipped_ips.reserve(2000);
    for (auto &ip : unique_ips) {
        if (file_content.empty()) {
            file_content += ip + "\n";
        } else {
            if (contains_pattern(file_content, ip)) {
                skipped_ips.push_back(ip);
            } else {
                file_content += ip + "\n";
            }
        }
    }
    cout << skipped_ips.size() << "\n";
    for (auto &ip : skipped_ips) {
        cout << ip << "\n";
    }

    return 0;
}