#include <bits/stdc++.h>
using namespace std;

int main(){
    string expr;
    getline(cin, expr);
    
    // Parse the expression into operators and numbers
    vector<char> operators;
    vector<string> numbers;
    int n = expr.size();
    int i = 0;
    bool has_initial_operator = false;
    
    // Determine if the expression starts with an operator
    if(i < n && (expr[i] == '+' || expr[i] == '-')){
        operators.push_back(expr[i]);
        has_initial_operator = true;
        i++;
    }
    else{
        operators.push_back('+'); // Assume '+' if no initial operator
    }
    
    // Parse numbers and subsequent operators
    while(i < n){
        // Parse number
        string num = "";
        while(i < n && isdigit(expr[i])){
            num += expr[i];
            i++;
        }
        numbers.push_back(num);
        
        // Parse operator
        if(i < n && (expr[i] == '+' || expr[i] == '-')){
            operators.push_back(expr[i]);
            i++;
        }
    }
    
    // Ensure operators.size() == numbers.size()
    if(operators.size() < numbers.size()){
        operators.insert(operators.begin(), '+');
    }
    
    // Pair operators with numbers
    vector<pair<char, string>> op_num;
    for(int j=0; j < numbers.size(); j++){
        op_num.emplace_back(operators[j], numbers[j]);
    }
    
    // Process each operator-number pair
    vector<pair<char, string>> new_op_num;
    for(auto &[op, num] : op_num){
        if(op == '+'){
            // Do not split, keep as is
            new_op_num.emplace_back('+', num);
        }
        else if(op == '-'){
            // Try to split the number
            if(num.size() >=2 ){
                // Find the smallest split position where the second part does not start with '0' unless it's '0'
                int split_pos = -1;
                for(int s=1; s < num.size(); s++){
                    string S2 = num.substr(s);
                    if(S2.size() ==1 || S2[0] != '0'){
                        split_pos = s;
                        break;
                    }
                }
                if(split_pos != -1){
                    string S1 = num.substr(0, split_pos);
                    string S2 = num.substr(split_pos);
                    // Insert '-S1' and '+S2'
                    new_op_num.emplace_back('-', S1);
                    new_op_num.emplace_back('+', S2);
                }
                else{
                    // Cannot split, keep as is
                    new_op_num.emplace_back('-', num);
                }
            }
            else{
                // Cannot split, keep as is
                new_op_num.emplace_back('-', num);
            }
        }
    }
    
    // Reconstruct the expression
    string result = "";
    for(int j=0; j < new_op_num.size(); j++){
        char op = new_op_num[j].first;
        string num = new_op_num[j].second;
        if(j ==0){
            if(has_initial_operator){
                // Include the initial operator as it was in the original expression
                result += op;
            }
            else{
                // Omit the '+' if it was assumed
                if(op != '+'){
                    result += op;
                }
                // If op is '+', do not add it
            }
        }
        else{
            // Include all other operators
            result += op;
        }
        result += num;
    }
    
    cout << result;
}