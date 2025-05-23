#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    // Read the target grid
    // Using 1-based indexing for rows and columns
    vector<vector<int>> target(N+1, vector<int>(N+1, 0));
    for(int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            cin >> target[y][x];
        }
    }
    
    // List to store XOR operations
    vector<tuple<int, int, int, int>> operations;
    
    // Iterate through each row
    for(int y=1; y<=N; y++){
        int x = 1;
        while(x <= N){
            // Find the start of a black segment
            while(x <= N && target[y][x] == 0){
                x++;
            }
            if(x > N) break;
            int L = x;
            // Find the end of the black segment
            while(x <= N && target[y][x] == 1){
                x++;
            }
            int R = x-1;
            // Add the XOR operation for this segment
            operations.emplace_back(L, R, y, y);
        }
    }
    
    // Output the result
    cout << operations.size() << "\n";
    for(auto &[L, R, T, B] : operations){
        cout << L << " " << R << " " << T << " " << B << "\n";
    }
    
    return 0;
}