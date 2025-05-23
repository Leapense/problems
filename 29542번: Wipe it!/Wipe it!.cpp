#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    string result = "";

    for (char c : s)
    {
        if (result.find(c) == string::npos)
        {
            result.push_back(c);
        }
    }

    cout << result << "\n";
    return 0;
}