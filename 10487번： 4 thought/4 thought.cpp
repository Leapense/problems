#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<char> operators = {'+', '-', '*', '/'};
    unordered_map<long long, string> expr_map;
    for(auto op1: operators){
        for(auto op2: operators){
            for(auto op3: operators){
                vector<long long> nums = {4,4,4,4};
                vector<char> ops = {op1, op2, op3};
                vector<long long> values = nums;
                vector<char> operations = ops;
                int n_ops = operations.size();
                for(int i=0;i<operations.size();){
                    if(operations[i] == '*' || operations[i] == '/'){
                        long long a = values[i];
                        long long b = values[i+1];
                        long long res;
                        if(operations[i] == '*') res = a * b;
                        else{
                            if(b == 0){
                                res = 0;
                            }
                            else{
                                res = a / b;
                            }
                        }
                        values.erase(values.begin()+i);
                        values.erase(values.begin()+i);
                        values.insert(values.begin()+i, res);
                        operations.erase(operations.begin()+i);
                    }
                    else{
                        i++;
                    }
                }
                while(operations.size()>0){
                    long long a = values[0];
                    long long b = values[1];
                    long long res;
                    if(operations[0] == '+') res = a + b;
                    else{
                        res = a - b;
                    }
                    values.erase(values.begin());
                    values.erase(values.begin());
                    values.insert(values.begin(), res);
                    operations.erase(operations.begin());
                }
                long long result = values[0];
                if(expr_map.find(result) == expr_map.end()){
                    string expr = "4 " + string(1, op1) + " 4 " + string(1, op2) + " 4 " + string(1, op3) + " 4 = " + to_string(result);
                    expr_map[result] = expr;
                }
            }
        }
    }
    int m;
    cin>>m;
    while(m--){
        long long n;
        cin>>n;
        if(expr_map.find(n)!=expr_map.end()) cout<<expr_map[n]<<"\n";
        else cout<<"no solution\n";
    }
}
