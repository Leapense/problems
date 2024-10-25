//=====================================================================
//   25275번:    Bar Classification                   
//   @date:   2024-10-24              
//   @link:   https://www.acmicpc.net/problem/25275  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string> grid(N);
	vector<int> row_ones(N, 0);
	vector<int> col_ones(N, 0);
	long long total_ones = 0;

	for(int i = 0; i < N; ++i){
        cin >> grid[i];
        for(int j = 0; j < N; ++j){
            if(grid[i][j] == '1'){
                row_ones[i]++;
                col_ones[j]++;
                total_ones++;
            }
        }
    }

	bool row_possible = false, col_possible = false;
    
    // Check for possible rows
    for(int i = 0; i < N; ++i){
        if(total_ones <= 2LL * row_ones[i]){
            row_possible = true;
            break;
        }
    }
    
    // Check for possible columns
    for(int j = 0; j < N; ++j){
        if(total_ones <= 2LL * col_ones[j]){
            col_possible = true;
            break;
        }
    }
    
    if(row_possible && col_possible){
        cout << "+\n";
    }
    else if(row_possible){
        cout << "-\n";
    }
    else{
        cout << "|\n";
    }

	return 0;
}
