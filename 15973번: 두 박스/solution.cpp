#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long x1a, y1a, x2a, y2a;
    long long x1b, y1b, x2b, y2b;
    if (!(cin >> x1a >> y1a >> x2a >> y2a)) return 0;
    if (!(cin >> x1b >> y1b >> x2b >> y2b)) return 0;
    long long ovX = min(x2a, x2b) - max(x1a, x1b);
    long long ovY = min(y2a, y2b) - max(y1a, y1b);
    if (ovX < 0 || ovY < 0) {
        cout << "NULL\n";
    } else if (ovX == 0 && ovY == 0) {
        cout << "POINT\n";
    } else if (ovX == 0 || ovY == 0) {
        cout << "LINE\n";
    } else {
        cout << "FACE\n";
    }
    return 0;
}