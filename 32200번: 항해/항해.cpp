#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    ll X, Y;
    cin >> N >> X >> Y;
    
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    
    ll total_meals =0;
    ll total_discard =0;
    
    for(int i=0;i<N;i++){
        ll Ai = A[i];
        ll ki = Ai / X;
        if(ki >0){
            total_meals += ki;
            if(Ai > ki * Y){
                total_discard += Ai - ki * Y;
            }
            // else, no discard
        }
        else{
            total_discard += Ai;
        }
    }
    
    cout << total_meals << "\n" << total_discard;
}