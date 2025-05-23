#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<pair<int, int>> peppers(N);
    for (int i = 0; i < N; ++i) {
        cin >> peppers[i].first >> peppers[i].second;
    }
    
    // Simulate the swapping process with proper conditions
    for (int i = 0; i < N - 1; ++i) {
        int age_i = peppers[i].first;
        int desire_i = peppers[i].second;
        int age_j = peppers[i + 1].first;
        int desire_j = peppers[i + 1].second;

        // Only swap if it's beneficial and adheres to the given rule
        if ((age_i > age_j && desire_i == 1 && desire_j == 0) || 
            (age_i < age_j && desire_i == 0 && desire_j == 1)) {
            swap(peppers[i], peppers[i + 1]);
        }
    }
    
    int satisfied = 0;
    // Calculate how many peppers are satisfied with their destiny
    for (int i = 0; i < N; ++i) {
        int age = peppers[i].first;
        int desire = peppers[i].second;
        
        // Determine if this pepper's purpose is fulfilled
        if ((age <= X && desire == 1) || (age > X && desire == 0)) {
            satisfied++;
        }
    }
    
    cout << satisfied << endl;
    return 0;
}
