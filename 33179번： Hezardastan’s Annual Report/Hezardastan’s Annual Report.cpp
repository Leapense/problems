#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
        if (pages[i] % 2 == 1)
        {
            pages[i]++;
        }
    }

    int total_sheets = 0;
    for (int i = 0; i < n; i++)
    {
        total_sheets += pages[i] / 2;
    }

    cout << total_sheets << endl;
    return 0;
}