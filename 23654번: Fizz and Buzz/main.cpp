#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string result;
    result.resize(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a % 3 == 0 && a % 5 != 0) {
            result[i] = 'F';
        } else if (a % 5 == 0 && a % 3 != 0) {
            result[i] = 'B';
        } else if (a % 15 == 0) {
            result[i] = 'B';
        }
    }

    cout << result << "\n";
    return 0;
}
