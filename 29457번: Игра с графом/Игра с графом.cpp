#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // Read m edges, but we don't need to store them
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        // No need to store edges for this solution
    }
    
    // Special case: n ==1 and m ==0
    if(n ==1 && m ==0){
        cout << "Draw";
        return 0;
    }
    
    // Calculate k = m - (n -1)
    int k = m - (n -1);
    
    if(k >0){
        if(k %2 ==1){
            // Bob loses
            cout << "Bob";
        }
        else{
            // Alice loses
            cout << "Alice";
        }
    }
    else{
        // Alice has to make the first move and remove a bridge, thus loses
        cout << "Alice";
    }
}