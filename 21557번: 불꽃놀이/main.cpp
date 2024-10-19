//=====================================================================
//   21557번:    불꽃놀이                   
//   @date:   2024-10-18              
//   @link:   https://www.acmicpc.net/problem/21557  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long long>A(N);
    for(auto &x:A) cin>>x;
    long long h = max(A[0], A[N-1]) - (N-2);
    cout<<h;
}
