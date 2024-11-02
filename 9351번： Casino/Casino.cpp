#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        string S;
        cin>>S;
        int n=S.size();
        int max_len=1;
        vector<pair<int, string>> palindromes;
        for(int i=0;i<n;i++){
            // 홀수 길이
            int l=i, r=i;
            while(l>=0 && r<n && S[l]==S[r]){
                int len = r-l+1;
                if(len > max_len){
                    max_len = len;
                    palindromes.clear();
                    if(len >1){
                        palindromes.emplace_back(l, S.substr(l, len));
                    }
                }
                else if(len == max_len && len >1){
                    palindromes.emplace_back(l, S.substr(l, len));
                }
                l--;
                r++;
            }
            // 짝수 길이
            l=i;
            r=i+1;
            while(l>=0 && r<n && S[l]==S[r]){
                int len = r-l+1;
                if(len > max_len){
                    max_len = len;
                    palindromes.clear();
                    if(len >1){
                        palindromes.emplace_back(l, S.substr(l, len));
                    }
                }
                else if(len == max_len && len >1){
                    palindromes.emplace_back(l, S.substr(l, len));
                }
                l--;
                r++;
            }
        }
        // 정렬: 시작 인덱스 내림차순
        sort(palindromes.begin(), palindromes.end(), [&](const pair<int, string> &a, const pair<int, string> &b)->bool{
            return a.first > b.first;
        });
        cout<<"Case #"<<tc<<":\n";
        for(auto &p: palindromes){
            cout<<p.second<<"\n";
        }
    }
}