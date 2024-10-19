//=====================================================================
//   21554번:    마법의 돌 장난감                   
//   @date:   2024-10-18              
//   @link:   https://www.acmicpc.net/problem/21554  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(auto &x:A) cin>>x;
    vector<pair<int,int>> operations;
    for(int i=1;i<=N;i++){
        if(A[i-1]==i) continue;
        int pos = -1;
        for(int j=i-1;j<N;j++) if(A[j]==i){ pos = j; break;}
        if(pos==-1){
            cout<<-1;
            return 0;
        }
        if(pos != i-1){
            operations.emplace_back(i, pos+1);
            reverse(A.begin()+i-1, A.begin()+pos+1);
            if(operations.size()>100){
                cout<<-1;
                return 0;
            }
        }
    }
    bool sorted_flag = true;
    for(int i=0;i<N;i++) if(A[i]!=i+1){ sorted_flag = false; break;}
    if(!sorted_flag){
        cout<<-1;
        return 0;
    }
    cout<<operations.size()<<"\n";
    for(auto &[l,r]:operations) cout<<l<<" "<<r<<"\n";
}