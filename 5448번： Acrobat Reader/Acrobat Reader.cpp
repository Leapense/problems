#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; };

Point rotate_point(const Point &p, int rotation) {
    switch(rotation) {
        case 0:
            return p;
        case 90:
            return Point{ -p.y, p.x };
        case 180:
            return Point{ -p.x, -p.y };
        case 270:
            return Point{ p.y, -p.x };
        default:
            return p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<Point> A(N);

        for(auto &p : A) cin >> p.x >> p.y;

        vector<Point> B(N);

        for(auto &p : B) cin >> p.x >> p.y;

        sort(B.begin(), B.end(), [&](const Point& a, const Point& b) -> bool {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });

        bool match_found = false;
        for (auto rotation : { 0, 90, 180, 270 }) {
            vector<Point> A_rot(N);

            for (int i = 0; i < N; i++) A_rot[i] = rotate_point(A[i], rotation);

            if(N == 1) {
                match_found = true;
                break;
            }
            sort(A_rot.begin(), A_rot.end(), [&](const Point& a, const Point& b) -> bool {
                if (a.x != b.x) return a.x < b.x;
                return a.y < b.y;
            });

            double dx_A = (double)(A_rot[1].x - A_rot[0].x);
            double dy_A = (double)(A_rot[1].y - A_rot[0].y);
            double d_A = sqrt(dx_A * dx_A + dy_A * dy_A);
            double dx_B = (double)(B[1].x - B[0].x);
            double dy_B = (double)(B[1].y - B[0].y);
            double d_B = sqrt(dx_B * dx_B + dy_B * dy_B);

            if (d_A == 0) {
                continue;
            }

            double s = d_B / d_A;
            double t_x = (double)B[0].x - s * (double)A_rot[0].x;
            double t_y = (double)B[0].y - s * (double)A_rot[0].y;

            vector<pair<double, double>> transformed_A(N);

            for (int i = 0; i < N; i++) {
                transformed_A[i].first = s * (double)A_rot[i].x + t_x;
                transformed_A[i].second = s * (double)A_rot[i].y + t_y;
            }

            sort(transformed_A.begin(), transformed_A.end(), [&](const pair<double, double>& a, const pair<double, double>& b) -> bool {
                if(abs(a.first - b.first) > 1e-6) return a.first < b.first;
                return a.second < b.second;
            });

            bool valid = true;
            for (int i = 0; i < N; i++) {
                if (abs(transformed_A[i].first - (double)B[i].x) > 1e-4 || abs(transformed_A[i].second - (double)B[i].y) > 1e-4) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                match_found = true;
                break;
            }
        }

        if (match_found) {
            cout << "okay\n";
        } else {
            cout << "mismatch!\n";
        }
    }

    return 0;
}