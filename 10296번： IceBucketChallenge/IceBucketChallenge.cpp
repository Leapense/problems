#include <iostream>
using namespace std;

typedef long long ll;

// Function to compute the ceiling of a division
ll ceil_division(ll numerator, ll denominator) {
    return (numerator + denominator - 1) / denominator;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll G, K;
        cin >> G >> K;
        ll P = 0;
        if(G <= 100){
            P = 0;
        }
        else{
            ll numerator = G - 100;
            ll denominator = 100*K - 90;
            // Since K >=1, denominator is always positive
            P = ceil_division(numerator, denominator);
        }
        cout << P << "\n";
    }
}
