#include <iostream>
#include <string>

using namespace std;

int main()
{
    string h;
    cin >> h;

    if (h == "1") {
        cout << 2 << "\n";
    } else {
        if ((h.length() > 1 || h[0] >= '2')) {
            cout << 1 << "\n";
        }
    }

    return 0;
}