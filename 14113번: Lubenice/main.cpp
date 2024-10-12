//=====================================================================
//   14113번:    Lubenice                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/14113  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D,E;
    cin>>A>>B>>C>>D>>E;
    int bags = A;
    bags += B;
    E = max(E - B, 0);
    bags += C;
    if(D >= C*2){
        D -= C*2;
    }
    else{
        int used_D = D;
        D =0;
        int remaining = C*2 - used_D;
        E = max(E - remaining,0);
    }
    bags += D /2;
    if(D%2==1){
        bags +=1;
        E = max(E -3,0);
    }
    bags += (E /5) + (E%5 >0?1:0);
    cout<<bags;
}
