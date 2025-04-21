// main.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m))   // if reading fails, bail out
        return 0;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<vector<bool>> ok(n, vector<bool>(m, false));

    // Row‐entrances: left and right
    for(int i = 0; i < n; ++i){
        // from left boundary until the first pillar
        for(int j = 0; j < m && grid[i][j]=='.'; ++j)
            ok[i][j] = true;
        // from right boundary until the first pillar
        for(int j = m-1; j >= 0 && grid[i][j]=='.'; --j)
            ok[i][j] = true;
    }

    // Column‐entrances: top and bottom
    for(int j = 0; j < m; ++j){
        // from top boundary until the first pillar
        for(int i = 0; i < n && grid[i][j]=='.'; ++i)
            ok[i][j] = true;
        // from bottom boundary until the first pillar
        for(int i = n-1; i >= 0 && grid[i][j]=='.'; --i)
            ok[i][j] = true;
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(grid[i][j]=='.' && ok[i][j])
                ++ans;

    cout << ans << "\n";
    return 0;
}

