#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Point> pts(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    int peak = 1;
    for (int i = 2; i < N - 1; i++)
    {
        if (pts[i].y > pts[peak].y)
        {
            peak = i;
        }
    }

    int bestLeft = peak - 1;
    ll minSlopeNum = pts[peak].y - pts[bestLeft].y;
    ll minSlopeDen = pts[peak].x - pts[bestLeft].x;

    for (int i = peak - 2; i >= 0; i--)
    {
        ll num = pts[peak].y - pts[i].y;
        ll den = pts[peak].x - pts[i].x;

        if (num * minSlopeDen <= minSlopeNum * den)
        {
            bestLeft = i;
            minSlopeNum = num;
            minSlopeDen = den;
        }
    }

    int bestRight = peak + 1;
    ll rMinSlopeNum = pts[peak].y - pts[bestRight].y;
    ll rMinSlopeDen = pts[bestRight].x - pts[peak].x;

    for (int i = peak + 2; i < N; i++)
    {
        ll num = pts[peak].y - pts[i].y;
        ll den = pts[i].x - pts[peak].x;
        if (num * rMinSlopeDen <= rMinSlopeNum * den)
        {
            bestRight = i;
            rMinSlopeNum = num;
            rMinSlopeDen = den;
        }
    }

    cout << pts[bestLeft].x << " " << pts[bestLeft].y << "\n";
    cout << pts[bestRight].x << " " << pts[bestRight].y << "\n";

    return 0;
}