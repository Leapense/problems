#include <bits/stdc++.h>
using namespace std;

struct Ball
{
    int pos;
    int dir;
};

class Simulation
{
public:
    int L, N, T;
    vector<Ball> balls;
    long long collision_count;

    Simulation() : collision_count(0) {}
    void input()
    {
        cin >> L >> N >> T;
        for (int i = 0; i < N; i++)
        {
            int s;
            char c;
            cin >> s >> c;

            Ball b;
            b.pos = s;
            b.dir = (c == 'R') ? 1 : -1;
            balls.push_back(b);
        }
    }

    void run()
    {
        for (int t = 1; t <= T; t++)
        {
            for (auto &b : balls)
            {
                b.pos += b.dir;
            }

            for (auto &b : balls)
            {
                if (b.pos == 0 || b.pos == L)
                {
                    b.dir *= -1;
                }
            }

            map<int, vector<int>> m;
            for (int i = 0; i < balls.size(); i++)
                m[balls[i].pos].push_back(i);

            for (auto &[k, v] : m)
            {
                if (v.size() >= 2)
                {
                    long long pairs = ((long long)v.size() * (v.size() - 1)) / 2;
                    collision_count += pairs;
                    for (auto idx : v)
                        balls[idx].dir *= -1;
                }
            }
        }
    }

    void output_result()
    {
        cout << collision_count;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Simulation sim;
    sim.input();
    sim.run();
    sim.output_result();

    return 0;
}