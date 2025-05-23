#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    long long l, r, k;
    cin >> l >> r >> k;
    
    int n = s.size();
    
    // Calculate the minimum and maximum initial cursor positions
    long long pos0_min = l + 1;
    long long pos0_max = n - r;
    
    // Check if there's a valid initial cursor position
    if(pos0_min > pos0_max){
        cout << "Impossible";
        return 0;
    }
    
    // Choose pos0 as pos0_min (can choose any within [pos0_min, pos0_max])
    long long pos0 = pos0_min;
    
    // Reconstruct the initial password
    string s0 = s;
    
    // Apply the reverse of the k change operations
    // For simplicity, assign all k changes to pos0
    // Calculate the total decrement
    long long total_decrement = k % 26;
    
    // Decrement the character at pos0
    char original_char = s[pos0 - 1];
    original_char = (original_char - 'a' - total_decrement + 26) % 26 + 'a';
    s0[pos0 - 1] = original_char;
    
    // Output the reconstructed password and initial cursor position
    cout << s0 << "\n" << pos0;
}
