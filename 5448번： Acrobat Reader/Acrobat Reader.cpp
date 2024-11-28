#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const double EPS = 1e-8;

struct Point {
    double x, y;
    Point(double x_=0, double y_=0): x(x_), y(y_) {}
};

void read_points(int N, vector<Point>& pts) {
    for(int i = 0; i < N; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        pts.emplace_back(xi, yi);
    }
}

void rotate_points(vector<Point>& pts, int angle) {
    for (auto& p : pts) {
        double x = p.x, y = p.y;
        if(angle == 90) {
            p.x = -y;
            p.y = x;
        } else if(angle == 180) {
            p.x = -x;
            p.y = -y;
        } else if(angle == 270) {
            p.x = y;
            p.y = -x;
        }
    }
}

void normalize_points(vector<Point>& pts, double& scale_factor) {
    double cx = 0, cy = 0;

    for (const auto& p : pts) {
        cx += p.x;
        cy += p.y;
    }

    cx /= pts.size();
    cy /= pts.size();

    for (auto& p : pts) {
        p.x -= cx;
        p.y -= cy;
    }

    double sum_sq = 0;

    for (const auto& p : pts) {
        sum_sq += p.x*p.x + p.y*p.y;
    }

    scale_factor = sqrt(sum_sq);
}

bool compare_point_sets(vector<Point>& set1, vector<Point>& set2) {
    const double mult = 1e6;

    vector<pll> pts1, pts2;
    for(const auto& p : set1) {
        ll x = ll(round(p.x * mult));
        ll y = ll(round(p.y * mult));
        pts1.emplace_back(x, y);
    }
    for(const auto& p : set2) {
        ll x = ll(round(p.x * mult));
        ll y = ll(round(p.y * mult));
        pts2.emplace_back(x, y);
    }
    sort(pts1.begin(), pts1.end());
    sort(pts2.begin(), pts2.end());
    return pts1 == pts2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<Point> pts1, pts2;
        read_points(N, pts1);
        read_points(N, pts2);

        bool matched = false;
        for(int angle : {0, 90, 180, 270}) {
            vector<Point> rotated_pts1 = pts1;
            rotate_points(rotated_pts1, angle);

            double scale1, scale2;
            normalize_points(rotated_pts1, scale1);
            normalize_points(pts2, scale2);

            double s = scale2 / scale1;
            for(auto& p : rotated_pts1) {
                p.x *= s;
                p.y *= s;
            }

            if(compare_point_sets(rotated_pts1, pts2)) {
                cout << "okay" << endl;
                matched = true;
                break;
            }
        }
        if(!matched) {
            cout << "mismatch!" << endl;
        }
    }
    return 0;
}