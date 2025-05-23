#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s.size() < 3 || s.substr(0, 2) != "io") {
        cout << "Incorrect" << endl;
        return 0;
    }

    for (int i = 2; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            cout << "Incorrect" << endl;
            return 0;
        }
    }

    cout << "Correct" << endl;

    return 0;
}