#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string initial, target;
    cin >> initial >> target;

    bool isAlternating = true;
    for (int i = 0; i < n; i++)
    {
        if (initial[i] == initial[(i + 1) % n])
        {
            isAlternating = false;
            break;
        }
    }

    if (isAlternating)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }

    return 0;
}