#include <bits/stdc++.h>
using namespace std;

struct Word {
    int number;
    int length;
};

// Function to check if a cell starts an across word
bool starts_across(int i, int j, int r, int c, const vector<string> &grid) {
    if (grid[i][j] == '@') return false;
    if (j > 0 && grid[i][j-1] != '@') return false;
    // Count letters to the right
    int cnt = 0;
    int k = j;
    while (k < c && grid[i][k] != '@') {
        cnt++;
        k++;
    }
    return cnt >= 3;
}

// Function to check if a cell starts a down word
bool starts_down(int i, int j, int r, int c, const vector<string> &grid) {
    if (grid[i][j] == '@') return false;
    // According to standard crossword rules, a down word starts if the cell above is black or it's the first row
    if (i > 0 && grid[i-1][j] != '@') return false;
    // Count letters downward
    int cnt = 0;
    int k = i;
    while (k < r && grid[k][j] != '@') {
        cnt++;
        k++;
    }
    return cnt >= 3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    int cwnum = 1;
    bool first = true;
    while(cin >> r >> c){
        if(r ==0 && c ==0) break;
        // Read grid
        vector<string> grid(r);
        for(int i=0;i<r;i++) {
            cin >> grid[i];
            // Ensure the grid has exactly c characters
            if(grid[i].size() < c){
                grid[i].resize(c, '@');
            }
            else if(grid[i].size() > c){
                grid[i] = grid[i].substr(0, c);
            }
        }
        // Assign numbers
        vector<vector<int>> numbering(r, vector<int>(c, 0));
        int num =1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '@') continue;
                bool across = starts_across(i, j, r, c, grid);
                bool down = starts_down(i, j, r, c, grid);
                if(across || down){
                    numbering[i][j] = num;
                    num++;
                }
            }
        }
        // Collect Across and Down words
        vector<Word> across_words;
        vector<Word> down_words;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(numbering[i][j] ==0) continue;
                // Check for across
                if(starts_across(i, j, r, c, grid)){
                    // Count letters across
                    int cnt =0;
                    int k = j;
                    while(k < c && grid[i][k] != '@'){
                        cnt++;
                        k++;
                    }
                    across_words.push_back(Word{numbering[i][j], cnt});
                }
                // Check for down
                if(starts_down(i, j, r, c, grid)){
                    // Count letters down
                    int cnt =0;
                    int k = i;
                    while(k < r && grid[k][j] != '@'){
                        cnt++;
                        k++;
                    }
                    down_words.push_back(Word{numbering[i][j], cnt});
                }
            }
        }
        // Sort the words by their number
        sort(across_words.begin(), across_words.end(), [&](const Word &a, const Word &b) -> bool{
            return a.number < b.number;
        });
        sort(down_words.begin(), down_words.end(), [&](const Word &a, const Word &b) -> bool{
            return a.number < b.number;
        });
        // Output
        if(!first){
            cout << "\n";
        }
        first = false;
        cout << "Crossword puzzle " << cwnum++ << "\n";
        cout << "Across\n";
        for(auto &w: across_words){
            cout << w.number << ".  (" << w.length << ")\n";
        }
        // Remove the blank line between Across and Down
        // cout << "\n"; // 삭제
        cout << "Down\n";
        for(auto &w: down_words){
            cout << w.number << ".  (" << w.length << ")\n";
        }
    }

    cout << "\n";
}