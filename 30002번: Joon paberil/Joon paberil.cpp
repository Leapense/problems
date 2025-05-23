#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull N;
    cin >> N;
    if(N == 0){
        cout << "1 1";
        return 0;
    }
    // Binary search to find m such that 4m(m+1) >= N
    ull low = 1, high = 2000000000; // 2e9 to cover up to N <1e18
    ull m = 1;
    while(low <= high){
        ull mid = low + (high - low) / 2;
        __int128 steps = (__int128)4 * mid * (mid +1);
        if(steps >= N){
            m = mid;
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    // Calculate steps before cycle m
    ull steps_before = 0;
    if(m >1){
        steps_before = 4 * (m-1) * m;
    }
    ull D = N - steps_before;
    // Determine (x, y) based on D
    ull x, y;
    if(D <= 2*m){
        x = 2*m;
        y = D;
    }
    else if(D <= 4*m -1){
        x = 2*m - (D - 2*m);
        y = 2*m;
    }
    else if(D <= 4*m){
        x = 1;
        y = 2*m +1;
    }
    else if(D <= 6*m){
        x = 1 + (D - 4*m);
        y = 2*m +1;
    }
    else{
        x = 2*m +1;
        y = 2*m +1 - (D - 6*m);
    }
    cout << x << " " << y;
}