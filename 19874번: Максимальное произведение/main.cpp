//=====================================================================
//   19874번:    Максимальное произведение                   
//   @date:   2024-10-14              
//   @link:   https://www.acmicpc.net/problem/19874  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    long long totalSum = 0;
    for(auto x : a) totalSum += x;
    long long currentSum = 0;
    __int128 maxProduct = -1;
    int splitIndex = 1;
    for(int i = 0; i < n - 1; i++){
        currentSum += a[i];
        __int128 product = (__int128)currentSum * (totalSum - currentSum);
        if(product > maxProduct){
            maxProduct = product;
            splitIndex = i + 1;
        }
    }
    cout << splitIndex;
}
