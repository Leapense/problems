#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Team
{
    int solved;
    ll A;
    ll B;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int T, P;
        cin >> T >> P;
        if (T == 0 && P == 0)
            break;
        vector<Team> teams(T, {0, 0, 0});
        vector<vector<pair<int, int>>> details(T, vector<pair<int, int>>(P, {0, 0}));
        for (int i = 0; i < T; i++)
        {
            for (int j = 0; j < P; j++)
            {
                string s;
                cin >> s;
                int slash = s.find('/');
                int att = stoi(s.substr(0, slash));
                string sub = s.substr(slash + 1);
                if (sub == "-")
                {
                    details[i][j] = {att, -1};
                }
                else
                {
                    int t = stoi(sub);
                    details[i][j] = {att, t};
                    teams[i].solved++;
                    teams[i].A += t;
                    teams[i].B += (att - 1);
                }
            }
        }
        vector<ll> origPenalty(T, 0);
        for (int i = 0; i < T; i++)
        {
            origPenalty[i] = teams[i].A + 20LL * teams[i].B;
        }
        // 순위 결정은 solved 수가 많고, solved 수가 같으면 총 패널티가 적은 순서
        vector<int> order(T);
        for (int i = 0; i < T; i++)
            order[i] = i;
        sort(order.begin(), order.end(), [&](int i, int j)
             {
            if(teams[i].solved != teams[j].solved) return teams[i].solved > teams[j].solved;
            return origPenalty[i] < origPenalty[j]; });
        ll lb = 1;
        ll ub = numeric_limits<ll>::max();
        bool possible = true;
        bool fixedFlag = false;
        ll fixedX = -1;
        // 같은 solved 그룹에 대해서만 제약을 고려한다.
        for (int i = 0; i < T && possible; i++)
        {
            for (int j = i + 1; j < T && possible; j++)
            {
                int ti = order[i], tj = order[j];
                if (teams[ti].solved != teams[tj].solved)
                    continue;
                ll orig_i = teams[ti].A + 20LL * teams[ti].B;
                ll orig_j = teams[tj].A + 20LL * teams[tj].B;
                // 동점인 경우: 새로운 EP에서도 반드시 같아야 함.
                if (orig_i == orig_j)
                {
                    if (teams[ti].A == teams[tj].A && teams[ti].B == teams[tj].B)
                        continue;
                    ll delta = teams[ti].A - teams[tj].A;
                    ll gamma = teams[ti].B - teams[tj].B;
                    if (gamma == 0)
                    {
                        possible = false;
                        break;
                    }
                    // 등식: delta + x * gamma = 0  ->  x = -delta/gamma
                    if ((-delta) % gamma != 0)
                    {
                        possible = false;
                        break;
                    }
                    ll candidate = (-delta) / gamma;
                    if (candidate <= 0)
                    {
                        possible = false;
                        break;
                    }
                    if (!fixedFlag)
                    {
                        fixedFlag = true;
                        fixedX = candidate;
                    }
                    else
                    {
                        if (fixedX != candidate)
                        {
                            possible = false;
                            break;
                        }
                    }
                }
                else
                {
                    // 동점이 아닌 경우: 원래 순위에 따라 부등식이 성립해야 함.
                    // 더 낮은 패널티가 더 좋은 순위.
                    bool origOrder = (orig_i < orig_j);
                    ll delta = teams[ti].A - teams[tj].A;
                    ll gamma = teams[ti].B - teams[tj].B;
                    // 부등식: delta + x * gamma < 0  if origOrder==true, else > 0.
                    if (gamma == 0)
                    {
                        if (origOrder)
                        {
                            if (!(delta < 0))
                            {
                                possible = false;
                                break;
                            }
                        }
                        else
                        {
                            if (!(delta > 0))
                            {
                                possible = false;
                                break;
                            }
                        }
                        continue;
                    }
                    if (origOrder)
                    {
                        // delta + x*gamma < 0
                        // gamma > 0 : x < -delta/gamma, gamma < 0 : x > -delta/gamma
                        if (gamma > 0)
                        {
                            double bound = -(double)delta / gamma;
                            // strict inequality: x <= floor(bound)-1 if bound is integer, else floor(bound)
                            ll cand = (ll)floor(bound);
                            if (fabs(bound - cand) < 1e-9)
                                cand--;
                            ub = min(ub, cand);
                        }
                        else
                        {
                            double bound = -(double)delta / gamma;
                            ll cand = (ll)ceil(bound);
                            if (fabs(bound - cand) < 1e-9)
                                cand++;
                            lb = max(lb, cand);
                        }
                    }
                    else
                    {
                        // orig_i > orig_j so delta + x*gamma > 0
                        if (gamma > 0)
                        {
                            double bound = -(double)delta / gamma;
                            ll cand = (ll)ceil(bound);
                            if (fabs(bound - cand) < 1e-9)
                                cand++;
                            lb = max(lb, cand);
                        }
                        else
                        {
                            double bound = -(double)delta / gamma;
                            ll cand = (ll)floor(bound);
                            if (fabs(bound - cand) < 1e-9)
                                cand--;
                            ub = min(ub, cand);
                        }
                    }
                }
            }
        }
        if (!possible || lb > ub)
        {
            cout << "0 0" << "\n";
        }
        else if (fixedFlag)
        {
            if (fixedX < lb || fixedX > ub)
            {
                cout << "0 0" << "\n";
            }
            else
            {
                cout << fixedX << " " << fixedX << "\n";
            }
        }
        else
        {
            cout << lb << " ";
            if (ub == numeric_limits<ll>::max())
                cout << "*" << "\n";
            else
                cout << ub << "\n";
        }
    }
    return 0;
}
