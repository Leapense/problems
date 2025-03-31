#include <iostream>
#include <string>
#include <set>
#include <cassert>
#include <vector>

using namespace std;

enum NodeType { CONSTANT, VARIABLE, NOT, AND, OR, IMP };

struct Node {
    NodeType type;
    bool value;
    char var;
    Node* child;
    Node* left;
    Node* right;
    Node(NodeType t) : type(t), value(false), var(0), child(nullptr), left(nullptr), right(nullptr) {}
};

string s;
int pos;

Node* parseFormula();

Node* parse() {
    if (pos >= s.size()) return nullptr;

    char c = s[pos];

    if (c == 'T' || c == 'F') {
        Node* node = new Node(CONSTANT);
        node->value = (c == 'T');
        pos++;
        return node;
    }

    if (c >= 'a' && c <= 'k') {
        Node* node = new Node(VARIABLE);
        node->var = c;
        pos++;
        return node;
    }
    
    if (c == '-') {
        pos++;
        Node* node = new Node(NOT);
        node->child = parse();
        return node;
    }

    if (c == '(') {
        pos++;
        Node* leftNode = parseFormula();

        NodeType op;
        if (s[pos] == '*') {
            op = AND;
            pos++;
        } else if (s[pos] == '+') {
            op = OR;
            pos++;
        } else if (s[pos] == '-') {
            pos++;
            assert(s[pos] == '>');
            pos++;
            op = IMP;
        } else {
            assert(false);
        }

        Node* rightNode = parseFormula();
        assert(s[pos] == ')');
        pos++;
        Node* node = new Node(op);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }
    return nullptr;
}

Node* parseFormula() {
    return parse();
}

void collectVariables(Node* node, set<char>& vars) {
    if (!node) return;
    if (node->type == VARIABLE) {
        vars.insert(node->var);
    }

    if (node->type == NOT) {
        collectVariables(node->child, vars);
    }

    if (node->type == AND || node->type == OR || node->type == IMP) {
        collectVariables(node->left, vars);
        collectVariables(node->right, vars);
    }
}

bool evaluate(Node* node, const bool assignment[128]) {
    switch(node->type) {
        case CONSTANT:
            return node->value;
        case VARIABLE:
            return assignment[(int)node->var];
        case NOT:
            return !evaluate(node->child, assignment);
        case AND:
            return evaluate(node->left, assignment) && evaluate(node->right, assignment);
        case OR:
            return evaluate(node->left, assignment) || evaluate(node->right, assignment);
        case IMP:
            return (!evaluate(node->left, assignment)) || evaluate(node->right, assignment);
    }
    return false;
}

void deleteAST(Node* node) {
    if (!node) return;
    if (node->type == NOT) {
        deleteAST(node->child);
    }
    if (node->type == AND || node->type == OR || node->type == IMP) {
        deleteAST(node->left);
        deleteAST(node->right);
    }

    delete node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(getline(cin, s)) {
        if (s == "#") break;
        pos = 0;
        Node* leftTree = parseFormula();
        assert(s[pos] == '=');
        pos++;
        Node* rightTree = parseFormula();

        set<char> vars;
        collectVariables(leftTree, vars);
        collectVariables(rightTree, vars);
        vector<char> varList(vars.begin(), vars.end());

        int n = varList.size();

        bool isTautology = true;
        
        for (int mask = 0; mask < (1 << n) && isTautology; mask++) {
            bool assignment[128] = {false};
            for (int i = 0; i < n; i++) {
                assignment[(int)varList[i]] = (mask & (1 << i));
            }

            bool leftVal = evaluate(leftTree, assignment);
            bool rightVal = evaluate(rightTree, assignment);

            if (leftVal != rightVal) {
                isTautology = false;
                break;
            }
        }

        cout << (isTautology ? "YES" : "NO") << "\n";

        deleteAST(leftTree);
        deleteAST(rightTree);
    }
    return 0;
}
