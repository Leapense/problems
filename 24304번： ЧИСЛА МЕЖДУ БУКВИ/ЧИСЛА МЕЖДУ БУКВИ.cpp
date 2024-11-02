#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    string sequence;

    cin >> N;
    cin >> sequence;

    bool foundNumber = false;
    string numberStr = "";

    for (char ch : sequence) {
        if (isdigit(ch)) {
            numberStr += ch;
        } else {
            if (!numberStr.empty()) {
                int number = std::stoi(numberStr);

                cout << N * number << "\n";

                foundNumber = true;
                numberStr.clear();
            }
        }
    }

    if (!numberStr.empty()) {
        int number = stoi(numberStr);
        cout << N * number << "\n";
        foundNumber = true;
    }

    if (!foundNumber) {
        cout << "N/A" << "\n";
    }

    return 0;

}