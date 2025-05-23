#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Z;
    cin >> Z;

    while(Z--) {
        long long N, K;
        cin >> N >> K;
        if (N % (K + 1) == 0) cout << "Wiktor\n";
        else cout << "Hektor\n";
    }

    return 0;
}