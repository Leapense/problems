#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint32;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int case_num =1;
    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        uint32 N1 = stoul(s1, nullptr, 16);
        uint32 N2 = stoul(s2, nullptr, 16);
        int k_left = -1, k_right = -1;
        for(int k=0; k<32; k++){
            uint32 left_rot, right_rot;
            if(k ==0){
                left_rot = N1;
                right_rot = N1;
            }
            else{
                left_rot = ((N1 <<k) | (N1 >> (32 -k))) & 0xFFFFFFFF;
                right_rot = ((N1 >>k) | (N1 << (32 -k))) & 0xFFFFFFFF;
            }
            if(left_rot == N2 && (k_left == -1 || k < k_left)){
                k_left = k;
            }
            if(right_rot == N2 && (k_right == -1 || k < k_right)){
                k_right = k;
            }
        }
        if(k_left == -1 && k_right == -1){
            cout << "Case #" << case_num++ << ": Not possible\n";
            continue;
        }
        if(k_left != -1 && k_right != -1){
            if(k_left < k_right){
                cout << "Case #" << case_num++ << ": " << k_left << " Left\n";
            }
            else if(k_right < k_left){
                cout << "Case #" << case_num++ << ": " << k_right << " Right\n";
            }
            else{
                cout << "Case #" << case_num++ << ": " << k_left << " Any\n";
            }
        }
        else{
            if(k_left != -1){
                cout << "Case #" << case_num++ << ": " << k_left << " Left\n";
            }
            else{
                cout << "Case #" << case_num++ << ": " << k_right << " Right\n";
            }
        }
    }
}