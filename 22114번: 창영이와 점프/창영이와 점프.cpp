/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 22114                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/22114                          #+#        #+#      #+#    */
/*   Solved: 2025/03/30 14:28:04 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> L(N - 1);
    for (int i = 0; i < N - 1; i++){
        cin >> L[i];
    }
    
    // 슬라이딩 윈도우: 윈도우 내에서 K를 초과하는 간격이 최대 1개여야 한다.
    int start = 0, count = 0, ans = 1;
    for (int end = 0; end < N - 1; end++){
        if(L[end] > K) count++;
        
        while(count > 1 && start <= end){
            if(L[start] > K) count--;
            start++;
        }
        
        // 현재 윈도우는 block[start]부터 block[end+1]까지 연속된 블럭
        ans = max(ans, end - start + 2);
    }
    
    cout << ans << "\n";
    return 0;
}
