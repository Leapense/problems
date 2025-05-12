#include <bits/stdc++.h>
using namespace std;

struct Rect {
    long long x, y, p, q;
};

char intersectionType(const Rect& A, const Rect& B)
{
    long long w = min(A.p, B.p) - max(A.x, B.x);
    long long h = min(A.q, B.q) - max(A.y, B.y);
    
    if (w > 0 && h > 0) return 'a';
    if (w == 0 && h == 0) return 'c';
    if ((w == 0) ^ (h == 0)) return 'b';
    return 'd';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 4; ++i) {
        Rect A, B;
        cin >> A.x >> A.y >> A.p >> A.q
            >> B.x >> B.y >> B.p >> B.q;
        cout << intersectionType(A, B) << "\n";
    }
    
    return 0;
}