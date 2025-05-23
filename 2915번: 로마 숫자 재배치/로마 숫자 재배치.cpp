#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, string>> generateRoman()
{
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    vector<pair<int, string>> roman;

    for (int i = 1; i < 100; i++)
    {
        int t = i / 10;
        int o = i % 10;

        string numeral = tens[t] + ones[o];
        roman.push_back({i, numeral});
    }

    return roman;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    string sortedInput = input;
    sort(sortedInput.begin(), sortedInput.end());

    vector<pair<int, string>> roman = generateRoman();
    int minVal = 1000;
    string answer = "";

    for (auto &p : roman)
    {
        string candidate = p.second;
        string sortedCandidate = candidate;
        sort(sortedCandidate.begin(), sortedCandidate.end());
        if (sortedCandidate == sortedInput)
        {
            if (p.first < minVal)
            {
                minVal = p.first;
                answer = candidate;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}