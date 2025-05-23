#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y;
    int id;
};

bool operator==(const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

struct KDNode
{
    Point point;
    int axis;
    KDNode *left, *right;
};

KDNode *buildKDTree(vector<Point>::iterator begin, vector<Point>::iterator end, int depth)
{
    if (begin >= end)
        return nullptr;
    int axis = depth % 2;
    auto cmp = [axis](const Point &a, const Point &b)
    {
        return (axis == 0 ? a.x < b.x : a.y < b.y);
    };

    size_t len = end - begin;
    auto mid = begin + len / 2;
    nth_element(begin, mid, end, cmp);
    KDNode *node = new KDNode;
    node->point = *mid;
    node->axis = axis;
    node->left = buildKDTree(begin, mid, depth + 1);
    node->right = buildKDTree(mid + 1, end, depth + 1);
    return node;
}

void nearestSearch(KDNode *node, const Point &target, Point &bestPoint, long long &bestDist)
{
    if (!node)
        return;
    long long dx = node->point.x - target.x;
    long long dy = node->point.y - target.y;
    long long d = dx * dx + dy * dy;

    if (node->point.id != target.id)
    {
        if (d < bestDist || (d == bestDist && node->point.id > bestPoint.id))
        {
            bestDist = d;
            bestPoint = node->point;
        }
    }

    int axis = node->axis;
    long long diff = (axis == 0 ? target.x - node->point.x : target.y - node->point.y);
    KDNode *first = (diff < 0 ? node->left : node->right);
    KDNode *second = (diff < 0 ? node->right : node->left);
    nearestSearch(first, target, bestPoint, bestDist);
    if (diff * diff < bestDist)
        nearestSearch(second, target, bestPoint, bestDist);
}

double currentX;

struct Segment
{
    int id;
    Point p, q;
    Point left, right;
};

vector<Segment> segs;

struct Event
{
    double x, y;
    int seg_id;
    bool isStart;
};

bool eventComparator(const Event &a, const Event &b)
{
    if (fabs(a.x - b.x) > 1e-9)
        return a.x < b.x;
    if (a.isStart != b.isStart)
        return a.isStart > b.isStart;
    return a.y < b.y;
}

double getY(const Segment &s, double x)
{
    if (s.left.x == s.right.x)
        return s.left.y;
    double t = (x - s.left.x) / (double)(s.right.x - s.left.x);
    return s.left.y + t * (s.right.y - s.left.y);
}

struct SegmentComp
{
    bool operator()(int i, int j) const
    {
        double y1 = getY(segs[i], currentX);
        double y2 = getY(segs[j], currentX);
        if (fabs(y1 - y2) > 1e-9)
        {
            return y1 < y2;
        }
        return i < j;
    }
};

int orientation(const Point &a, const Point &b, const Point &c)
{
    long long val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

bool onSegment(const Point &a, const Point &b, const Point &c)
{
    if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y))
        return true;
    return false;
}

bool segmentsIntersect(const Segment &a, const Segment &b, int m)
{
    bool adjacent = (abs(a.id - b.id) == 1) || (a.id == 0 && b.id == m - 1) || (b.id == 0 && a.id == m - 1);
    int o1 = orientation(a.p, a.q, b.p);
    int o2 = orientation(a.p, a.q, b.q);
    int o3 = orientation(b.p, b.q, a.p);
    int o4 = orientation(b.p, b.q, a.q);

    bool intersectFlag = false;
    if (o1 != o2 && o3 != o4)
        intersectFlag = true;
    else if (o1 == 0 && onSegment(a.p, b.p, a.q))
        intersectFlag = true;
    else if (o2 == 0 && onSegment(a.p, b.q, a.q))
        intersectFlag = true;
    else if (o3 == 0 && onSegment(b.p, a.p, b.q))
        intersectFlag = true;
    else if (o4 == 0 && onSegment(b.p, a.q, b.q))
        intersectFlag = true;

    if (!intersectFlag)
        return false;
    if (!adjacent)
        return true;

    Point shared;
    bool found = false;
    if (a.p == b.p)
    {
        shared = a.p;
        found = true;
    }
    else if (a.p == b.q)
    {
        shared = a.p;
        found = true;
    }
    else if (a.q == b.p)
    {
        shared = a.q;
        found = true;
    }
    else if (a.q == b.q)
    {
        shared = a.q;
        found = true;
    }
    if (!found)
        return true;

    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0)
    {
        vector<Point> pts = {a.p, a.q, b.p, b.q};
        sort(pts.begin(), pts.end(), [](const Point &p1, const Point &p2)
             {
            if (p1.x == p2.x) return p1.y < p2.y;
            return p1.x < p2.x; });
        if (!(pts[1] == pts[2] && pts[1] == shared))
            return true;
        else
            return false;
    }

    return false;
}

bool check_simple_polygon(const vector<Point> &poly)
{
    int m = poly.size();
    if (m < 3)
        return false;
    segs.clear();
    segs.resize(m);

    for (int i = 0; i < m; i++)
    {
        Segment s;
        s.id = i;
        s.p = poly[i];
        s.q = poly[(i + 1) % m];
        if (s.p.x < s.q.x || (s.p.x == s.q.x && s.p.y <= s.q.y))
        {
            s.left = s.p;
            s.right = s.q;
        }
        else
        {
            s.left = s.q;
            s.right = s.p;
        }
        segs[i] = s;
    }

    vector<Event> events;
    events.reserve(2 * m);

    for (int i = 0; i < m; i++)
    {
        Event e1, e2;
        e1.x = segs[i].left.x;
        e1.y = segs[i].left.y;
        e1.seg_id = i;
        e1.isStart = true;
        e2.x = segs[i].right.x;
        e2.y = segs[i].right.y;
        e2.seg_id = i;
        e2.isStart = false;
        events.push_back(e1);
        events.push_back(e2);
    }

    sort(events.begin(), events.end(), eventComparator);
    currentX = events[0].x;
    set<int, SegmentComp> active;
    for (auto &e : events)
    {
        currentX = e.x;
        int sid = e.seg_id;
        if (e.isStart)
        {
            auto it = active.insert(sid).first;
            if (it != active.begin())
            {
                auto prev = it;
                prev--;
                if (segmentsIntersect(segs[*prev], segs[sid], m))
                    return false;
            }

            auto nxt = it;
            nxt++;

            if (nxt != active.end())
            {
                if (segmentsIntersect(segs[*nxt], segs[sid], m))
                    return false;
            }
        }
        else
        {
            auto it = active.find(sid);
            if (it != active.end())
            {
                auto prev = it, nxt = it;
                bool hasPrev = false, hasNext = false;
                if (it != active.begin())
                {
                    hasPrev = true;
                    prev--;
                }

                nxt++;

                if (nxt != active.end())
                    hasNext = true;
                if (hasPrev && hasNext)
                {
                    if (segmentsIntersect(segs[*prev], segs[*nxt], m))
                        return false;
                }

                active.erase(it);
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].id = i + 1;
    }

    vector<Point> pts = points;
    KDNode *kdRoot = buildKDTree(pts.begin(), pts.end(), 0);
    vector<int> f(N + 1, -1);
    function<void(KDNode *, const Point &, Point &, long long &)> nearest = [&](KDNode *node, const Point &target, Point &bestPoint, long long &bestDist)
    {
        if (!node)
            return;
        long long dx = node->point.x - target.x;
        long long dy = node->point.y - target.y;
        long long d = dx * dx + dy * dy;
        if (node->point.id != target.id)
        {
            if (d < bestDist || (d == bestDist && node->point.id > bestPoint.id))
            {
                bestDist = d;
                bestPoint = node->point;
            }
        }

        int axis = node->axis;
        long long diff = (axis == 0 ? target.x - node->point.x : target.y - node->point.y);
        KDNode *first = (diff < 0 ? node->left : node->right);
        KDNode *second = (diff < 0 ? node->right : node->left);
        nearest(first, target, bestPoint, bestDist);
        if (diff * diff < bestDist)
        {
            nearest(second, target, bestPoint, bestDist);
        }
    };

    for (int i = 0; i < N; i++)
    {
        Point bestPoint;
        bestPoint.id = -1;
        bestPoint.x = 0;
        bestPoint.y = 0;
        long long bestDist = LLONG_MAX;
        nearest(kdRoot, points[i], bestPoint, bestDist);
        f[points[i].id] = bestPoint.id;
    }

    function<void(KDNode *)> freeKD = [&](KDNode *node)
    {
        if (!node)
            return;
        freeKD(node->left);
        freeKD(node->right);
        delete node;
    };

    freeKD(kdRoot);

    vector<int> state(N + 1, 0);
    int ans = -1;

    for (int i = 1; i <= N; i++)
    {
        if (state[i] != 0)
            continue;
        vector<int> path;
        int cur = i;
        while (true)
        {
            state[cur] = 1;
            path.push_back(cur);
            int nxt = f[cur];
            if (state[nxt] == 0)
            {
                cur = nxt;
                continue;
            }
            else if (state[nxt] == 1)
            {
                int pos = -1;
                for (int j = 0; j < path.size(); j++)
                {
                    if (path[j] == nxt)
                    {
                        pos = j;
                        break;
                    }
                }

                vector<int> cycle(path.begin() + pos, path.end());

                if (cycle.size() >= 3)
                {
                    vector<Point> poly;
                    for (int v : cycle)
                    {
                        poly.push_back(points[v - 1]);
                    }

                    if (check_simple_polygon(poly))
                    {
                        ans = max(ans, (int)cycle.size());
                    }
                }

                break;
            }
            else
            {
                break;
            }
        }

        for (int v : path)
            state[v] = 2;
    }

    cout << ans << "\n";
    return 0;
}