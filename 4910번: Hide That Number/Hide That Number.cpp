#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;

    int test_case = 1;

    while (cin >> S) {
        if (S == "0") break;
        int k = S.size();

        long long mod = 0;

        for (char c : S) {
            mod = (mod * 10 + (c - '0')) % 11;
        }

        int a;
        if (k % 2) {
            a = (-mod * 10) % 11;
        } else {
            a = (-mod) % 11;
        }

        if (a < 0) a += 11;
        if (a < 0 || a > 10) {
            cout << test_case << ". IMPOSSIBLE\n";
            test_case++;
            continue;
        }

        string R = to_string(a) + S;
        string Q = "";

        int carry = 0;

        for (char c : R) {
            int num = carry * 10 + (c - '0');
            int q_digit = num / 11;
            carry = num % 11;
            Q += to_string(q_digit);
        }

        size_t first_non_zero = Q.find_first_not_of('0');
        if(first_non_zero == string::npos){
            Q="0";
        }
        else{
            Q = Q.substr(first_non_zero);
        }
        if(Q.size() <k){
            Q = string(k - Q.size(), '0') + Q;
        }
        if(Q.size()==k && Q[0]!='0'){
            cout<<test_case<<". "<<Q<<"\n";
        }
        else{
            cout<<test_case<<". IMPOSSIBLE\n";
        }
        test_case++;
    }

    return 0;
}