//=====================================================================
//   20732번:    Proofs                   
//   @date:   2024-10-16              
//   @link:   https://www.acmicpc.net/problem/20732  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    auto power = [](int e) -> ll {
        ll res=1;
        for(int i=0;i<e;i++) res *=26;
        return res;
    };
    // Precompute prefix sums
    ll prefix[6];
    prefix[0]=0;
    for(int i=1;i<=5;i++) prefix[i]=prefix[i-1]+power(i);
    auto get_index = [&](const string &s) -> ll {
        ll idx = prefix[s.size()-1];
        ll val=0;
        for(char c:s) val = val*26 + (c-'A');
        idx += val;
        return idx;
    };
    const ll MAX_INDEX = prefix[5]+power(5);
    vector<char> concluded(MAX_INDEX, 0);
    string token;
    for(int line=1; line<=n; line++){
        vector<string> tokens;
        while(cin >> token && token != "->"){
            tokens.push_back(token);
        }
        string conclusion;
        cin >> conclusion;
        bool valid=true;
        for(auto &ass: tokens){
            ll idx = get_index(ass);
            if(idx >= MAX_INDEX || !concluded[idx]){
                valid=false;
                break;
            }
        }
        if(!valid){
            cout << line;
            return 0;
        }
        ll concl_idx = get_index(conclusion);
        if(concl_idx < MAX_INDEX) concluded[concl_idx]=1;
    }
    cout << "correct";
}