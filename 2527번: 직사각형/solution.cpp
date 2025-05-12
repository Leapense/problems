#include <bits/stdc++.h>
using namespace std;

struct Rect {
    long long x, y, p, q;
};

char intersectionType(const Rect& A, const Rect& B)
{
    long long w = min(A.p, B.p) - max(A.x, B.x);
    long long h = min(A.q, B.q) - max(A.y, B.y);
    
    if (w > 0 && h > 0) return 'a';                                     // 직사각형
    if (w == 0 && h == 0) return 'c';                                   // 점
    if ((w == 0 && h > 0) || (h == 0 && w > 0)) return 'b';             // 선분 : 한 축은 0, 다른 축은 양수
    return 'd';                                                         // 겹치지 않음
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