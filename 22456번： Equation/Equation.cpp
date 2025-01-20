#include <bits/stdc++.h>
using namespace std;

enum NodeType { TCONST, FCONST, VAR, NOT_OP, AND_OP, OR_OP, IMP_OP };
struct Node {
    NodeType type;
    string var;
    Node* l;
    Node* r;
    Node(): type(TCONST), var(""), l(nullptr), r(nullptr) {}
};

vector<string> tokens;
int pos;

bool isVarChar(char c) {
    return (c >= 'a' && c <= 'k');
}

void tokenize(const string &s) {
    tokens.clear();
    pos = 0;
    int i = 0;
    while (i < (int)s.size()) {
        if (isspace(s[i])) {
            i++;
            continue;
        }
        if (s[i] == '(' || s[i] == ')' || s[i] == '=' || s[i] == '+' || s[i] == '*' || s[i] == '-') {
            if (s[i] == '-' && i + 1 < (int)s.size() && s[i+1] == '>') {
                tokens.push_back("->");
                i += 2;
            } else {
                tokens.push_back(string(1, s[i]));
                i++;
            }
        } else if (s[i] == 'T' || s[i] == 'F') {
            tokens.push_back(string(1, s[i]));
            i++;
        } else if (isVarChar(s[i])) {
            tokens.push_back(string(1, s[i]));
            i++;
        } else {
            i++;
        }
    }
}

Node* parseFormula();

Node* parse() {
    return parseFormula();
}

Node* parseFormula() {
    if (pos >= (int)tokens.size()) return nullptr;
    string t = tokens[pos++];
    if (t == "T") {
        Node* node = new Node();
        node->type = TCONST;
        return node;
    } else if (t == "F") {
        Node* node = new Node();
        node->type = FCONST;
        return node;
    } else if (isVarChar(t[0]) && t.size() == 1) {
        Node* node = new Node();
        node->type = VAR;
        node->var = t;
        return node;
    } else if (t == "-") {
        Node* node = new Node();
        node->type = NOT_OP;
        node->l = parseFormula();
        return node;
    } else if (t == "(") {
        Node* leftNode = parseFormula();
        string op = tokens[pos++];
        NodeType nt;
        if (op == "*") nt = AND_OP;
        else if (op == "+") nt = OR_OP;
        else nt = IMP_OP;
        Node* rightNode = parseFormula();
        string closing = tokens[pos++];
        Node* node = new Node();
        node->type = nt;
        node->l = leftNode;
        node->r = rightNode;
        return node;
    }
    return nullptr;
}

bool evaluate(Node* root, const unordered_map<string,bool> &m) {
    if (!root) return false;
    if (root->type == TCONST) return true;
    if (root->type == FCONST) return false;
    if (root->type == VAR) return m.at(root->var);
    if (root->type == NOT_OP) return !evaluate(root->l, m);
    if (root->type == AND_OP) return evaluate(root->l, m) && evaluate(root->r, m);
    if (root->type == OR_OP) return evaluate(root->l, m) || evaluate(root->r, m);
    bool lv = evaluate(root->l, m);
    bool rv = evaluate(root->r, m);
    return (!lv) || rv;
}

void collectVars(Node* root, unordered_set<string> &st) {
    if (!root) return;
    if (root->type == VAR) st.insert(root->var);
    collectVars(root->l, st);
    collectVars(root->r, st);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        string line;
        if(!getline(cin, line)) break;
        if(line=="#") break;
        int eqPos = line.find('=');
        if(eqPos == string::npos) continue;
        string leftExpr = line.substr(0, eqPos);
        string rightExpr = line.substr(eqPos+1);
        tokenize(leftExpr);
        Node* leftRoot = parse();
        tokenize(rightExpr);
        Node* rightRoot = parse();
        unordered_set<string> varSet;
        collectVars(leftRoot, varSet);
        collectVars(rightRoot, varSet);
        vector<string> vars(varSet.begin(), varSet.end());
        bool alwaysEqual = true;
        int n = (int)vars.size();
        for(int mask=0; mask<(1<<n); mask++){
            unordered_map<string,bool> val;
            for(int i=0; i<n; i++){
                bool b = ((mask>>i)&1);
                val[vars[i]] = b;
            }
            bool lv = evaluate(leftRoot, val);
            bool rv = evaluate(rightRoot, val);
            if(lv != rv) {
                alwaysEqual = false;
                break;
            }
        }
        cout << (alwaysEqual ? "YES\n" : "NO\n");
    }
    return 0;
}
