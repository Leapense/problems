#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Ball {
    double x, v;
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int x1_i, v1_i, x2_i, v2_i, T_i;
    cin >> x1_i >> v1_i;
    cin >> x2_i >> v2_i;
    cin >> T_i;

    Ball ball1, ball2;
    ball1.x = x1_i;
    ball1.v = v1_i;
    ball2.x = x2_i;
    ball2.v = v2_i;

    double T = T_i;
    double current_time = 0.0;

    while(current_time < T) {
        if (ball1.v == ball2.v) {
            double delta_t = T - current_time;
            ball1.x += ball1.v * delta_t;
            ball2.x += ball2.v * delta_t;
            current_time = T;
            break;
        }

        double t_collide = (ball2.x - ball1.x) / (ball1.v - ball2.v);

        if (t_collide <= current_time || t_collide < 0) {
            double delta_t = T - current_time;
            ball1.x += ball1.v * delta_t;
            ball2.x += ball2.v * delta_t;

            current_time = T;
            break;
        }

        if (t_collide > T) {
            double delta_t = T - current_time;
            ball1.x += ball1.v * delta_t;
            ball2.x += ball2.v * delta_t;
            current_time = T;
            break;
        }

        double delta_t = t_collide - current_time;
        ball1.x += ball1.v * delta_t;
        ball2.x += ball2.v * delta_t;

        swap(ball1.v, ball2.v);

        current_time = t_collide;
    }

    long long final_x1 = round(ball1.x);
    long long final_v1 = round(ball1.v);
    long long final_x2 = round(ball2.x);
    long long final_v2 = round(ball2.v);

    cout << final_x1 << " " << final_v1 << "\n";
    cout << final_x2 << " " << final_v2 << "\n";

    return 0;
}