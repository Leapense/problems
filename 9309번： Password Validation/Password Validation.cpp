#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    string forbiddenWords[4] = {"password", "virginia", "cavalier", "code"};
    while (N--) {
        string pwd; cin >> pwd;
        bool valid = true;
        if ((int)pwd.size() < 9 || (int)pwd.size() > 20) {
            cout << "Invalid Password\n";
            continue;
        }
        int lowerCount=0, upperCount=0, digitCount=0, specialCount=0;
        string specials = "!@#$%^&*.,;/?";
        for (int i=0; i<(int)pwd.size(); i++) {
            if (pwd[i]>='a' && pwd[i]<='z') lowerCount++;
            else if (pwd[i]>='A' && pwd[i]<='Z') upperCount++;
            else if (pwd[i]>='0' && pwd[i]<='9') digitCount++;
            else if (specials.find(pwd[i])!=string::npos || pwd[i]==':') specialCount++;
        }
        if (lowerCount<2 || upperCount<2 || digitCount<1 || specialCount<2) {
            cout << "Invalid Password\n";
            continue;
        }
        for (int i=0; i+2<(int)pwd.size(); i++) {
            if (pwd[i]==pwd[i+1] && pwd[i+1]==pwd[i+2]) {
                valid = false; break;
            }
        }
        if (!valid) {
            cout << "Invalid Password\n";
            continue;
        }
        string alnum;
        for (auto &c: pwd) {
            if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')) {
                alnum.push_back(tolower((unsigned char)c));
            }
        }
        {
            string rev = alnum;
            reverse(rev.begin(), rev.end());
            if (alnum == rev && !alnum.empty()) {
                cout << "Invalid Password\n";
                continue;
            }
        }
        {
            string revAlnum = alnum;
            reverse(revAlnum.begin(), revAlnum.end());
            for (int i=0; i<4; i++) {
                if (alnum.find(forbiddenWords[i])!=string::npos || revAlnum.find(forbiddenWords[i])!=string::npos) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) {
            cout << "Invalid Password\n";
            continue;
        }
        cout << "Valid Password\n";
    }
}