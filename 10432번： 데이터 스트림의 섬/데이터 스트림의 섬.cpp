#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P;
    cin>>P;
    while(P--){
        int T;
        int a[12];
        cin>>T;
        for(int i=0;i<12;i++) cin>>a[i];
        int count=0;
        for(int i=1;i<=10;i++){
            for(int j=i;j<=10;j++){
                bool flag=true;
                for(int k=i;k<=j;k++) if(a[k] <= a[i-1] || a[k] <= a[j+1]){
                    flag=false;
                    break;
                }
                if(flag) count++;
            }
        }
        cout<<T<<" "<<count<<"\n";
    }
}