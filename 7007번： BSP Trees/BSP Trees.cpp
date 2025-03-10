#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Point
{
    int x, z;
};

struct Object
{
    string label;
    vector<Point> vertices;
};

struct Plane
{
    Point p1, p2;
};

double side(const Plane &plane, const Point &pt)
{
    return (plane.p2.x - plane.p1.x) * (pt.z - plane.p1.z) - (plane.p2.z - plane.p1.z) * (pt.x - plane.p1.x);
}

void partitionObjects(const vector<Object> &objects, const Plane &plane, vector<Object> &front, vector<Object> &back)
{
    Point test = {0, -1000000};
    double testVal = side(plane, test);
    int viewerSign = (testVal > 0 ? 1 : -1);
    for (const auto &obj : objects)
    {
        bool smaeAsViewer = true, oppositeToViewer = true;
        for (const auto &pt : obj.vertices)
        {
            double d = side(plane, pt);
            int s = (d > 0 ? 1 : -1);
            if (s != viewerSign)
                smaeAsViewer = false;
            if (s != -viewerSign)
                oppositeToViewer = false;
        }

        if (smaeAsViewer)
            front.push_back(obj);
        else if (oppositeToViewer)
            back.push_back(obj);
        else
        {
            front.push_back(obj);
            back.push_back(obj);
        }
    }
}

void bspTraversal(int idx, const vector<Plane> &planes, vector<Object> objects, string &order)
{
    if (idx == planes.size() || objects.size() <= 1)
    {
        vector<string> labels;
        for (auto &obj : objects)
            labels.push_back(obj.label);
        sort(labels.begin(), labels.end());
        for (auto &s : labels)
            order += s;
        return;
    }

    vector<Object> front, back;
    partitionObjects(objects, planes[idx], front, back);
    bspTraversal(idx + 1, planes, back, order);
    bspTraversal(idx + 1, planes, front, order);
}

int main()
{
    int n;
    cin >> n;
    vector<Object> objects(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        objects[i].label = string(1, 'A' + i);
        objects[i].vertices.resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> objects[i].vertices[j].x >> objects[i].vertices[j].z;
        }
    }
    int p;
    cin >> p;
    vector<Plane> planes(p);
    for (int i = 0; i < p; i++)
    {
        cin >> planes[i].p1.x >> planes[i].p1.z >> planes[i].p2.x >> planes[i].p2.z;
    }

    string order = "";
    bspTraversal(0, planes, objects, order);
    cout << order << endl;

    return 0;
}