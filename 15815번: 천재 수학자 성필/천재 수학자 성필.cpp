#include <bits/stdc++.h>
using namespace std;

// infix 연산으로 바꾸는 문제
int main() {
    string s;
    cin >> s;
    stack<long long> st;

    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long res;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            st.push(res);
        }
    }
    cout << st.top() << endl;

    return 0;
}