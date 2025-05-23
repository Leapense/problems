#include <iostream>
using namespace std;

int main() {
    long long w, h;
    cin >> w >> h;

    if (w > h) {
        swap(w, h);
    }
    
    long long max_area_one_square = w * w;
    
    long long max_area_two_squares;
    if (h >= 2 * w) {
        max_area_two_squares = 2 * (w * w);
    } else {
        long long side1 = w;
        long long side2 = h - w;
        max_area_two_squares = (side1 * side1) + (side2 * side2);
    }
    
    cout << max(max_area_one_square, max_area_two_squares) << endl;
    
    return 0;
}