#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    long long maxRectangles = -1;
    long long maxArea = -1;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int p = (a - 2) / d + 1;
        int q = (b - 2) / d + 1;

        long long rectangles = (long long)(p + 1) * (q + 1);
        long long area = (long long)a * b;

        if (rectangles > maxRectangles) {
            maxRectangles = rectangles;
            maxArea = area;
        } else if (rectangles == maxRectangles && area > maxArea) {
            maxArea = area;
        }
    }

    cout << maxArea << '\n';
    return 0;
}