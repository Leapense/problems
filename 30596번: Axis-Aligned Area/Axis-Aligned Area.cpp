#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    // Sorting the array to ensure a[0] <= a[1] <= a[2] <= a[3]
    sort(a, a + 4);

    // The maximum area is formed by taking the two largest sticks for one dimension
    // and the two smallest for the other dimension.
    int max_area = a[0] * a[2];

    cout << max_area << endl;
    return 0;
}