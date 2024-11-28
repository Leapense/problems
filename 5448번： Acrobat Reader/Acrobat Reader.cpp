#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

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
    for(auto& p : pts) {
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
        // For 0 degrees, do nothing
    }
}

void normalize_points(const vector<Point>& pts, double& scale_factor, Point& centroid, vector<Point>& normalized_pts) {
    // Compute centroid
    double cx = 0, cy = 0;
    for(const auto& p : pts) {
        cx += p.x;
        cy += p.y;
    }
    cx /= pts.size();
    cy /= pts.size();
    centroid.x = cx;
    centroid.y = cy;

    // Subtract centroid and store in normalized_pts
    normalized_pts.clear();
    for(const auto& p : pts) {
        normalized_pts.emplace_back(p.x - cx, p.y - cy);
    }

    // Compute scale factor (RMS distance)
    double sum_sq = 0;
    for(const auto& p : normalized_pts) {
        sum_sq += p.x * p.x + p.y * p.y;
    }
    scale_factor = sqrt(sum_sq);
}

bool compare_point_sets(const vector<Point>& set1, const vector<Point>& set2) {
    const double mult = 1e8; // Increased multiplier for better precision

    multiset<pll> pts1, pts2;

    for(const auto& p : set1) {
        ll x = ll(round(p.x * mult));
        ll y = ll(round(p.y * mult));
        pts1.emplace(x, y);
    }
    for(const auto& p : set2) {
        ll x = ll(round(p.x * mult));
        ll y = ll(round(p.y * mult));
        pts2.emplace(x, y);
    }

    return pts1 == pts2;
}

int main() {
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
            Point centroid1, centroid2;
            vector<Point> norm_pts1, norm_pts2;

            normalize_points(rotated_pts1, scale1, centroid1, norm_pts1);
            normalize_points(pts2, scale2, centroid2, norm_pts2);

            // Scale norm_pts1 to match scale of norm_pts2
            double s = scale2 / scale1;
            for(auto& p : norm_pts1) {
                p.x *= s;
                p.y *= s;
            }

            // Translate norm_pts1 to match centroid of pts2
            for(auto& p : norm_pts1) {
                p.x += centroid2.x;
                p.y += centroid2.y;
            }

            // Now compare norm_pts1 with pts2
            if(compare_point_sets(norm_pts1, pts2)) {
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
