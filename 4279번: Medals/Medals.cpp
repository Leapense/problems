#include <bits/stdc++.h>
using namespace std;

struct Country {
    string name;
    int g, s, b;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int c;
        cin >> c;
        if (c == 0) {
            break;
        }
        
        vector<Country> countries(c);
        int total_medals = 0;

        int canada_g = -1, canada_s = -1, canada_b = -1;

        for (int i = 0; i < c; i++) {
            cin >> countries[i].name >> countries[i].g >> countries[i].s >> countries[i].b;

            total_medals += countries[i].g + countries[i].s + countries[i].b;

            if (countries[i].name == "Canada") {
                canada_g = countries[i].g;
                canada_s = countries[i].s;
                canada_b = countries[i].b;
            }
        }

        if (canada_g == -1) {
            cout << "Canada cannot win.\n";
            continue;
        }

        bool can_win = false;

        for (int j = 0; j <= 6 && !can_win; j++) {
            for (int k = 0; k <= 6 && !can_win; k++) {
                for (int l = 0; l <= 6 && !can_win; l++) {
                    double w_g = (j == 0) ? 1.0 : 1.0 / pow((double)total_medals, j);
                    double w_s = (k == 0) ? 1.0 : 1.0 / pow((double)total_medals, k);
                    double w_b = (l == 0) ? 1.0 : 1.0 / pow((double)total_medals, l);

                    double canada_score = w_g * canada_g + w_s * canada_s + w_b * canada_b;

                    bool is_better = true;

                    for (auto &country : countries) {
                        if (country.name == "Canada") continue;
                        double country_score = country.g * w_g + country.s * w_s + country.b * w_b;

                        if (country_score >= canada_score - 1e-9) {
                            is_better = false;
                            break;
                        }
                    }

                    if (is_better) {
                        can_win = true;
                        break;
                    }
                }
            }
        }

        if (can_win) {
            cout << "Canada wins!\n";
        } else {
            cout << "Canada cannot win.\n";
        }
        
    }
}