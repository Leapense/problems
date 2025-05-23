#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

char getBankCode(const string& account) {
    size_t slash = account.find('/');
    if (slash != string::npos && slash + 1 < account.size()) {
        return account[slash + 1];
    }

    return '0';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A;
    while(cin >> A) {
        if (A == 0) {
            break;
        }

        unordered_map<string, double> accounts;

        for (int i = 0; i < A; ++i) {
            string acc;
            double balance;
            cin >> acc >> balance;
            accounts[acc] = balance;
        }

        string cmd;

        while(cin >> cmd) {
            if (cmd == "end") {
                break;
            }

            if (cmd == "create") {
                string acc;
                cin >> acc;
                cout << "create: ";
                if (accounts.find(acc) != accounts.end()) {
                    cout << "already exists\n";
                } else {
                    accounts[acc] = 0;
                    cout << "ok\n";
                }
            } else if(cmd == "deposit") {
                string acc;
                double amount;
                cin >> acc >> amount;

                cout << "deposit " << fixed << setprecision(2) << amount << ": ";

                if (accounts.find(acc) == accounts.end()) {
                    cout << "no such account\n";
                } else {
                    accounts[acc] += amount;
                    cout << "ok\n";
                }
            } else if(cmd == "withdraw") {
                string acc;
                double amount;
                cin >> acc >> amount;

                cout << "withdraw " << fixed << setprecision(2) << amount << ": ";

                if (accounts.find(acc) == accounts.end()) {
                    cout << "no such account\n";
                } else {
                    if (accounts[acc] < amount - 1e-9) {
                        cout << "insufficient funds\n";
                    } else {
                        accounts[acc] -= amount;
                        cout << "ok\n";
                    }
                }
            } else if(cmd == "transfer") {
                string src, tgt;
                double amount;

                cin >> src >> tgt >> amount;

                cout << "transfer " << fixed << setprecision(2) << amount << ": ";

                if (accounts.find(src) == accounts.end() || accounts.find(tgt) == accounts.end()) {
                    cout << "no such account\n";
                } else {
                    if (src == tgt) {
                        cout << "same account\n";
                    } else {
                        if (accounts[src] < amount - 1e-9) {
                            cout << "insufficient funds\n";
                        } else {
                            accounts[src] -= amount;
                            accounts[tgt] += amount;
                            char srcBank = getBankCode(src);
                            char tgtBank = getBankCode(tgt);
                            if (srcBank == tgtBank) {
                                cout << "ok\n";
                            } else {
                                cout << "interbank\n";
                            }
                        }
                    }
                }
            } else {
                string rest;
                getline(cin, rest);
            }
        }

        cout << "end\n\n";
    }
    cout << "goodbye\n";

    return 0;
}