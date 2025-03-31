#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <set>
#include <vector>

enum NodeType { CONSTANT, VARIABLE, NOT, AND, OR, IMP };

struct Node {
    NodeType type;
    bool value;
    char var;
    Node* child;
    Node* left;
    Node* right;
    Node(NodeType t);
};

std::string processLine(const std::string& line);

void freeAST(Node* node);
#endif
