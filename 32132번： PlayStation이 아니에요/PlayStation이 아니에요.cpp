#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int N;
    cin >> N;
    string s;
    cin >> s;

    while(true)
    {
        vector<bool> to_delete(s.size(), false);
        bool found = false;

        for (int i = 2; i < s.size(); i++) {
            if (s[i - 2] == 'P' && s[i - 1] == 'S' && (s[i] == '4' || s[i] == '5')) {
                to_delete[i] = true;
                found = true;
            }
        }

        if (!found) {
            break;
        }

        string new_s = "";

        for (int i = 0; i < s.size(); i++) {
            if(!to_delete[i]) {
                new_s += s[i];
            }
        }
        s = new_s;
    }

    cout << s;

    return 0;
}