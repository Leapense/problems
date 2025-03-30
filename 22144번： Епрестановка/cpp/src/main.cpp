#include "main.h"

void solve(istream &in, ostream &out) {
    int n, m;
    in >> n >> m;
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        in >> p[i];
    }
    
    UnionFind uf(n);
    
    // 순열 p에 따라 연결 요소 구성
    for (int i = 1; i <= n; ++i) {
        uf.unite(i, p[i]);
    }
    
    // 에프레스타노우카 z: 1과 2를 연결
    uf.unite(1, 2);
    
    while (m--) {
        int a, b;
        in >> a >> b;
        out << (uf.find(a) == uf.find(b) ? "Yes" : "No") << "\n";
    }
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif
