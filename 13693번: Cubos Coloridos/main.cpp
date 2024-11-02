//=====================================================================
//   13693번:    Cubos Coloridos                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/13693  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

// Function to rotate the cube around the x-axis
string rotate_x(const string& cube){
    // [U, L, F, R, B, D] -> [F, L, D, R, U, B]
    string rotated = cube;
    rotated[0] = cube[2]; // U = F
    rotated[2] = cube[5]; // F = D
    rotated[5] = cube[4]; // D = B
    rotated[4] = cube[0]; // B = U
    return rotated;
}

// Function to rotate the cube around the y-axis
string rotate_y(const string& cube){
    // [U, L, F, R, B, D] -> [R, U, F, D, B, L]
    string rotated = cube;
    rotated[0] = cube[3]; // U = R
    rotated[3] = cube[5]; // R = D
    rotated[5] = cube[1]; // D = L
    rotated[1] = cube[0]; // L = U
    return rotated;
}

// Function to rotate the cube around the z-axis
string rotate_z(const string& cube){
    // [U, L, F, R, B, D] -> [U, F, R, B, L, D]
    string rotated = cube;
    char original_L = cube[1];
    rotated[1] = cube[2]; // L = F
    rotated[2] = cube[3]; // F = R
    rotated[3] = cube[4]; // R = B
    rotated[4] = original_L; // B = original L
    return rotated;
}

// Function to generate all unique orientations of the cube
vector<string> generate_orientations(const string& cube){
    set<string> visited;
    queue<string> q;
    q.push(cube);
    visited.insert(cube);
    
    while(!q.empty()){
        string current = q.front(); q.pop();
        
        string rx = rotate_x(current);
        if(!visited.count(rx)){
            q.push(rx);
            visited.insert(rx);
        }
        
        string ry = rotate_y(current);
        if(!visited.count(ry)){
            q.push(ry);
            visited.insert(ry);
        }
        
        string rz = rotate_z(current);
        if(!visited.count(rz)){
            q.push(rz);
            visited.insert(rz);
        }
    }
    
    vector<string> orientations;
    for(auto &s: visited){
        orientations.push_back(s);
    }
    return orientations;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N){
        if(N == 0) break;
        vector<string> cubes;
        for(int i=0; i<N; ++i){
            string U, L, F, R, B, D;
            cin >> U;
            cin >> L >> F >> R >> B;
            cin >> D;
            string cube = U + L + F + R + B + D;
            cubes.push_back(cube);
        }
        // Now, for each cube, find its minimal canonical form
        set<string> unique_cubes;
        for(auto &cube: cubes){
            vector<string> orientations = generate_orientations(cube);
            string min_form = "";
            for(auto &s: orientations){
                if(min_form.empty() || s < min_form){
                    min_form = s;
                }
            }
            unique_cubes.insert(min_form);
        }
        // Output the number of unique types
        cout << unique_cubes.size() << "\n";
    }
}
