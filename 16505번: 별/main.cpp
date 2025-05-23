#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> makePattern(int n)
{
    if (n == 0)
    {
        return {"*"};
    }

    vector<string> prev = makePattern(n - 1);
    vector<string> pattern;

    for (size_t i = 0; i < prev.size(); i++)
    {
        string gap(i, ' ');
        pattern.push_back(prev[i] + gap + prev[i]);
    }

    for (const auto &line : prev)
    {
        pattern.push_back(line);
    }

    return pattern;
}

int main()
{
    int N;
    cin >> N;

    vector<string> result = makePattern(N);

    for (const string &line : result)
    {
        cout << line << "\n";
    }

    return 0;
}