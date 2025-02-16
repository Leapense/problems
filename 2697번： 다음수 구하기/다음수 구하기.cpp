#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string A;
        cin >> A;
        if (next_permutation(A.begin(), A.end()))
        {
            cout << A << "\n";
        }
        else
        {
            cout << "BIGGEST\n";
        }
    }

    return 0;
}