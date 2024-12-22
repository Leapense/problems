#include <bits/stdc++.h>
using namespace std;

struct Token {
    char sign;
    string number;
    bool signExplicit;
};

vector<Token> parseExpression(const string &expr) {
    vector<Token> tokens;

    bool firstCharIsSign = false;
    char currentSign = '+';
    bool signExplicit = false;
    int i = 0;

    if (!expr.empty() && (expr[0] == '+' || expr[0] == '-')) {
        currentSign = expr[0];
        signExplicit = true;
        firstCharIsSign = true;
        i = 1;
    }
    
    string currentTokenDigits;
    
    for (; i < (int)expr.size(); i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            if (!currentTokenDigits.empty()) {
                tokens.push_back(Token{currentSign, currentTokenDigits, signExplicit});
            }
            currentSign = expr[i];
            signExplicit = true;
            currentTokenDigits.clear();
        }
        else {
            currentTokenDigits.push_back(expr[i]);
        }
    }

    if (!currentTokenDigits.empty()) {
        tokens.push_back(Token{currentSign, currentTokenDigits, signExplicit});
    }
    
    return tokens;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string expr;
    cin >> expr;

    vector<Token> tokens = parseExpression(expr);
    
    ostringstream out;
    bool firstToken = true;
    
    for (auto &tk : tokens) {
        char s = tk.sign;
        const string &num = tk.number;
        bool explicitSign = tk.signExplicit;
        
        if (s == '+') {
            if (firstToken) {
                if (explicitSign) {
                    out << '+' << num;
                } else {
                    out << num;
                }
            } else {
                out << '+' << num;
            }
        }
        else {
            
            if (!num.empty()) {

                if (firstToken) {
                    out << '-' << num[0];
                } else {
                    out << '-' << num[0];
                }

                for (int i = 1; i < (int)num.size(); i++) {
                    out << '+' << num[i];
                }
            }
        }
        
        firstToken = false;
    }
    
    cout << out.str() << "\n";
    return 0;
}