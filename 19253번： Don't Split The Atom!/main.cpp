#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        cout << (n % 2 == 0 ? "A" : "B") << "\n";
    }
    return 0;
}