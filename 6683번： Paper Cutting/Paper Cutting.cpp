#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        ll A, B, C, D, E, F;
        cin >> A >> B >> C >> D >> E >> F;

        if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0 && F == 0) break;

        vector<pair<pair<ll, ll>, pair<ll, ll>>> orientations;

        orientations.emplace_back(make_pair(A, B), make_pair(C, D));
        orientations.emplace_back(make_pair(A, B), make_pair(D, C));
        orientations.emplace_back(make_pair(B, A), make_pair(C, D));
        orientations.emplace_back(make_pair(B, A), make_pair(D, C));

        ll min_cuts = LLONG_MAX;

        for (auto &[grid, card] : orientations) {
            ll rows = grid.first;
            ll cols = grid.second;
            ll card_w = card.first;
            ll card_h = card.second;
            ll grid_w = cols * card_w;
            ll grid_h = rows * card_h;

            vector<pair<ll, ll>> sheet_orients = {make_pair(E, F), make_pair(F, E)};

            for (auto &[sheet_w, sheet_h] : sheet_orients) {
                if (grid_w <= sheet_w && grid_h <= sheet_h) {
                    ll cuts = 0;
                    if (grid_w < sheet_w) cuts += 1;
                    if (grid_h < sheet_h) cuts += 1;
                    ll total_cuts = cuts + (A * B - 1);
                    min_cuts = min(min_cuts, total_cuts);
                }
            }
        }
        if (min_cuts != LLONG_MAX) {
            cout << "The minimum number of cuts is " << min_cuts << "." << endl;
        } else {
            cout << "The paper is too small." << endl;
        }
    }

    return 0;
}