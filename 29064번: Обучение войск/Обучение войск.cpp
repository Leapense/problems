#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ready_count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ready_count++;
        }
    }

    int needed_ready = ceil(n / 2.0);

    int additional_needed = max(0, needed_ready - ready_count);

    cout << additional_needed << endl;

    return 0;
}