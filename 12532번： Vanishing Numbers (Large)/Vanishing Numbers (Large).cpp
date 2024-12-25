#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,ll> parseFraction(const string &s) {
    string dec = s.substr(2);
    ll numerator = 0, denominator = 1;
    for (char c : dec) {
        numerator = numerator * 10 + (c - '0');
        denominator *= 10;
    }
    return {numerator, denominator};
}

int getEliminationRound(ll num, ll den) {
    for(int round=1; round<=30; round++){
        ll t = num*3;
        ll integerPart = t / den;
        ll remainder = t % den;
        if (integerPart == 1 || (integerPart == 1 && remainder == 0) || (integerPart == 2 && remainder == 0)){
            return round;
        }
        if (integerPart == 1) {
            return round;
        } else if (integerPart == 2) {
            num = t - 2*den;
        } else {
            num = remainder;
        }
    }
    return 999999;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int testCase=1; testCase<=T; testCase++){
        int N;
        cin >> N;
        vector<string> inputValues(N);
        vector<pair<ll,ll>> fractions(N);
        vector<int> elimRound(N);
        for(int i=0; i<N; i++){
            cin >> inputValues[i];
            fractions[i] = parseFraction(inputValues[i]);
        }
        for(int i=0; i<N; i++){
            elimRound[i] = getEliminationRound(fractions[i].first, fractions[i].second);
        }
        vector<int> idx(N);
        iota(idx.begin(), idx.end(), 0);
        auto cmp = [&](int a, int b){
            if(elimRound[a] != elimRound[b]) return elimRound[a] < elimRound[b];
            __int128 left = (__int128)fractions[a].first*fractions[b].second;
            __int128 right = (__int128)fractions[b].first*fractions[a].second;
            return left < right;
        };
        sort(idx.begin(), idx.end(), cmp);
        cout << "Case #" << testCase << ":\n";
        for(int i : idx) {
            cout << inputValues[i] << "\n";
        }
    }
    return 0;
}