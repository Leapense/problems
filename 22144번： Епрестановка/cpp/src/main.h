#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) : parent(n + 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
        }
    }
};

void solve(istream &in, ostream &out);

#endif // MAIN_H
