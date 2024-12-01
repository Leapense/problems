#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> w(n);
    vector<int> m(n);
    unordered_map<int, int> resource_to_city;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        resource_to_city[m[i]] = i;
    }
    
    vector<bool> visited(n, false);
    int cycles = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = resource_to_city[w[current]];
            }
            cycles++;
        }
    }
    
    cout << cycles << '\n';
    
    return 0;
}