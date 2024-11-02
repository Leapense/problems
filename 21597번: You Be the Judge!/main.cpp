//=====================================================================
//   21597번:    You Be the Judge!                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/21597  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fast exponentiation
ll power_mod(ll a, ll d, ll n){
    ll res=1;
    a %= n;
    while(d > 0){
        if(d & 1) res = (__int128(res) * a) % n;
        a = (__int128(a) * a) % n;
        d >>=1;
    }
    return res;
}

// Deterministic Miller-Rabin for n < 4,759,123,141
bool is_prime(ll n){
    if(n <2) return false;
    int r=0;
    ll d = n-1;
    while(d %2 ==0){
        d /=2;
        r++;
    }
    vector<ll> bases = {2,7,61};
    for(auto a: bases){
        if(a >=n) continue;
        ll x = power_mod(a, d, n);
        if(x ==1 || x ==n-1) continue;
        bool cont_outer = false;
        for(int i=0;i<r-1;i++){
            x = (__int128(x) * x) % n;
            if(x == n-1){
                cont_outer = true;
                break;
            }
        }
        if(cont_outer) continue;
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<string> tokens;
    while(getline(cin, s)){
        int n = s.size();
        int i=0;
        while(i<n){
            while(i<n && isspace(s[i])) i++;
            if(i>=n) break;
            int start = i;
            while(i<n && !isspace(s[i])) i++;
            tokens.emplace_back(s.substr(start, i-start));
        }
    }
    if(tokens.size() !=3){
        cout<<0;
        return 0;
    }
    auto is_valid_number = [&](const string &num)->bool{
        if(num.empty()) return false;
        for(char c:num) if(!isdigit(c)) return false;
        if(num.size() >1 && num[0]=='0') return false;
        return true;
    };
    for(auto &token: tokens) if(!is_valid_number(token)) {cout<<0; return 0;}
    ll A, B, C;
    try{
        A = stoll(tokens[0]);
        B = stoll(tokens[1]);
        C = stoll(tokens[2]);
    }
    catch(...){
        cout<<0;
        return 0;
    }
    if(A <=3 || A >1000000000 || A%2 !=0){
        cout<<0;
        return 0;
    }
    if(B <=0 || C <=0){
        cout<<0;
        return 0;
    }
    if(!is_prime(B) || !is_prime(C)){
        cout<<0;
        return 0;
    }
    if(B + C != A){
        cout<<0;
        return 0;
    }
    cout<<1;
}