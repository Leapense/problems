#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// 함수: 정수 x의 천장 제곱근을 반환
ull ceil_sqrt_func(ull x){
    if(x == 0) return 0;
    ull l = 0, r = 1;
    while(r * r < x) r <<=1;
    while(l < r){
        ull m = l + (r - l) /2;
        if(m * m >= x){
            r = m;
        }
        else{
            l = m +1;
        }
    }
    return l;
}

// 함수: 정수 x의 바닥 제곱근을 반환
ull floor_sqrt_func(ull x){
    if(x ==0) return 0;
    ull l =0, r =1;
    while((r * r) <=x) r <<=1;
    while(l < r){
        ull m = l + (r - l +1)/2;
        if(m * m <=x){
            l = m;
        }
        else{
            r = m -1;
        }
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull N;
    cin >> N;
    
    // Compute H_start and H_end using integer-based ceil and floor sqrt
    ull H_start;
    if(N ==0){
        H_start =1;
    }
    else{
        // To avoid division by zero
        ull x = (N +1) /2;
        H_start = ceil_sqrt_func(x);
    }
    
    ull H_end = floor_sqrt_func(N) + 100000; // Adding 1e5 as buffer
    
    // To prevent H_end from being excessively large, cap it
    // Maximum H_end for N=1e16 is floor(sqrt(1e16)) +1e5=1e8 +1e5=100100000
    if(H_end > 141421356){ // floor(sqrt(2*1e16)) ~1.41421356e8
        H_end = 141421356;
    }
    
    ull min_S = ULLONG_MAX;
    
    for(ull H = H_start; H <= H_end; H++){
        ull W = (N + H -1) / H; // ceil(N / H)
        ull ceil_H_half = (H +1) /2;
        if(W >= ceil_H_half && W <= 2 * H){
            ull S = W * H - N;
            if(S < min_S){
                min_S = S;
                if(S ==0){
                    break; // Can't get smaller than 0
                }
            }
        }
    }
    
    cout << min_S;
}