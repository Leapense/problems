#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    // Reading the distances between adjacent rivers
    vector<int> verticalDistances(n - 1);
    vector<int> horizontalDistances(e - 1);

    // Sum the vertical distances
    double d_n = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> verticalDistances[i];
        d_n += verticalDistances[i];
    }

    // Sum the horizontal distances
    double d_e = 0;
    for (int i = 0; i < e - 1; ++i) {
        cin >> horizontalDistances[i];
        d_e += horizontalDistances[i];
    }

    // Calculate the minimum diagonal flight distance using the Pythagorean theorem
    int ans = ceil(hypot(d_n, d_e)); // Rounds up the hypotenuse value to the nearest integer

    // Output the result
    cout << ans << endl;
    return 0;
}
