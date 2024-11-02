//=====================================================================
//   27919번:    UDPC 파티                   
//   @date:   2024-10-30              
//   @link:   https://www.acmicpc.net/problem/27919  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string V;
    cin >> V;
    
    // Initialize counts
    int U_count = 0, D_count = 0, P_count = 0, C_count = 0;
    
    // Count occurrences
    for(char c : V){
        if(c == 'U') U_count++;
        else if(c == 'D') D_count++;
        else if(c == 'P') P_count++;
        else if(c == 'C') C_count++;
    }
    
    // Calculate maximum possible votes for U
    long long Max_U = (long long)U_count + C_count;
    
    // Determine if U can win
    bool U_can_win = (Max_U > D_count && Max_U > P_count);
    
    // Determine if D can win (D + P > U)
    bool D_can_win = ((long long)D_count + P_count > U_count);
    
    // Determine if P can win (D + P > U)
    bool P_can_win = ((long long)D_count + P_count > U_count);
    
    // Collect results in order U, D, P
    string result = "";
    if(U_can_win) result += "U";
    if(D_can_win) result += "D";
    if(P_can_win) result += "P";
    
    // If no mascot can win, output 'C'
    if(result.empty()){
        cout << "C\n";
    }
    else{
        cout << result << "\n";
    }
    
    return 0;
}