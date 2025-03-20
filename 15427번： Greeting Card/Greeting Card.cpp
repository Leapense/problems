#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};
struct Hash
{
    size_t operator()(const Point &p) const
    {
        return ((size_t)p.x << 32) | (unsigned int)p.y;
    }
};

bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<Point, Hash> s;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
        s.insert(pts[i]);
    }

    vector<Point> offsets = {{2018, 0}, {0, 2018}, {1680, 1118}, {1680, -1118}, {1118, 1680}, {1118, -1680}};

    long long cnt = 0;

    for (auto &p : pts)
    {
        for (auto &d : offsets)
        {
            Point np = {p.x + d.x, p.y + d.y};
            if (s.find(np) != s.end())
            {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}