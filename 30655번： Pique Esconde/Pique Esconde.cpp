#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break; // Termination condition
        
        vector<bool> found(n + 1, false); // Use a vector to keep track of found children
        
        int foundChild;
        for (int i = 0; i < n - 2; ++i) {
            cin >> foundChild;
            found[foundChild] = true; // Mark the child as found
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!found[i] && i != m) { // Find the child who is not found and is not the seeker
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}