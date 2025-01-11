#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> values(n);

    for (auto &c : values) cin >> c;
    string s;
    getline(cin, s);
    while (s.empty()) getline(cin, s);

    vector<string> tokens;
    string token;

    stringstream ss(s);
    while (ss >> token) tokens.push_back(token);

    unordered_map<char, char> var_map;

    for (int i = 0; i < n; i++) var_map['A' + i] = values[i];

    stack<char> st;

    for (auto &tok : tokens) {
        if (var_map.find(tok[0]) != var_map.end()) {
            st.push(var_map[tok[0]]);
        } else {
            if (tok[0] == '*') {
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();
                st.push((a == 'T' && b == 'T') ? 'T' : 'F');
            } else if (tok[0] == '+') {
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();
                st.push((a == 'T' || b == 'T') ? 'T' : 'F');
            } else if (tok[0] == '-') {
                char a = st.top(); st.pop();
                st.push((a == 'T') ? 'F' : 'T');
            }
        }
    }

    cout << st.top();
}