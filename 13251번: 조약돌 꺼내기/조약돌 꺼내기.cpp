#include<bits/stdc++.h>
using namespace std;

double comb(int n, int k){
    if(k > n) return 0.0;
    if(k ==0 || k ==n) return 1.0;
    double res =1.0;
    for(int i=1;i<=k;i++){
        res = res * (n - i +1) / i;
    }
    return res;
}

int main(){
    int M;
    cin>>M;
    vector<int> c(M);
    for(auto &x:c) cin>>x;
    int K;
    cin>>K;
    long long N=0;
    for(auto x:c) N +=x;
    if(K > N){
        printf("0.0\n");
        return 0;
    }
    double total = comb(N, K);
    if(total ==0.0){
        printf("0.0\n");
        return 0;
    }
    double sum =0.0;
    for(auto x:c){
        if(x >= K){
            sum += comb(x, K);
        }
    }
    double prob = sum / total;
    printf("%.15lf\n", prob);
}
