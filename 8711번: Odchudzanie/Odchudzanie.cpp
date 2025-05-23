#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    int max_loss = 0;
    int max_start_weight = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        if (weights[i] > max_start_weight) {
            max_start_weight = weights[i];
        }
        // Calculate potential loss if max_start_weight is used as the starting point
        int current_loss = max_start_weight - weights[i];
        if (current_loss > max_loss) {
            max_loss = current_loss;
        }
    }
    
    cout << max_loss << "\n";
    
    return 0;
}
