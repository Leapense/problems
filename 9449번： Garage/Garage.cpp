#include <iostream>
using namespace std;

int main() {
    int W, H, w, h;
    cin >> W >> H >> w >> h;

    int garage_width = W / w;
    int garage_height = H / h;

    garage_width = (garage_width + 1) / 2;
    garage_height = (garage_height + 1) / 2;

    cout << garage_width * garage_height << endl;
}