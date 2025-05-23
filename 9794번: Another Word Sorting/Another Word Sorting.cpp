#include <bits/stdc++.h>
using namespace std;

struct Word {
    string s;
    long long score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<Word> words;
    string w;
    while(cin >> w){
        long long sum = 0;
        long long bonus = 0;
        int n = w.size();
        vector<bool> used(n, false);
        for(int i=0;i<n;i++) sum += (w[i]-'a'+1);
        for(int i=0;i<n-1;i++){
            if(w[i] == w[i+1] && !used[i] && !used[i+1]){
                bonus += 2*(w[i]-'a'+1);
                used[i] = used[i+1] = true;
            }
        }
        words.push_back(Word{w, sum + bonus});
    }
    sort(words.begin(), words.end(), [&](const Word &a, const Word &b) -> bool{
        if(a.score != b.score) return a.score > b.score;
        return a.s < b.s;
    });
    for(auto &word : words) cout << word.s << "\n";
}