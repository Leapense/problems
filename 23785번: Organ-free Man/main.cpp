//=====================================================================
//   23785번:    Organ-free Man                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/23785  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y ==0){
        cout << 0;
        return 0;
    }
    int factorial[10];
    factorial[0]=1;
    for(int i=1;i<=9;i++) factorial[i]=factorial[i-1]*i;
    int max_sum = min(y, 3628800);
    vector<bool> visited(max_sum+1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
    for(int d=1; d<=9; d++){
        if(factorial[d] > y) continue;
        pq.emplace((long long)d, factorial[d]);
        visited[factorial[d]]=true;
    }
    while(!pq.empty()){
        auto [x, s] = pq.top();
        pq.pop();
        if(s == y){
            cout << x;
            return 0;
        }
        for(int d=0; d<=9; d++){
            long long new_x = x*10 +d;
            int new_s = s + factorial[d];
            if(new_s > y) continue;
            if(!visited[new_s]){
                pq.emplace(new_x, new_s);
                visited[new_s]=true;
            }
        }
    }
    return 0;
}
