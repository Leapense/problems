#include <bits/stdc++.h>
using namespace std;

struct MedalCount {
    int gold = 0;
    int silver = 0;
    int bronze = 0;
};

bool compareCountries(const pair<string, MedalCount>& a, const pair<string, MedalCount>& b) {
    if (a.second.gold != b.second.gold)
        return a.second.gold > b.second.gold;
    if (a.second.silver != b.second.silver)
        return a.second.silver > b.second.silver;
    if (a.second.bronze != b.second.bronze)
        return a.second.bronze > b.second.bronze;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, MedalCount> countryMedals;

    for (int i = 0; i < n; ++i) {
        string gold, silver, bronze;
        cin >> gold >> silver >> bronze;

        countryMedals[gold].gold += 1;
        countryMedals[silver].silver += 1;
        countryMedals[bronze].bronze += 1;
    }

    vector<pair<string, MedalCount>> countries;

    for (auto &entry : countryMedals) {
        countries.emplace_back(entry);
    }

    sort(countries.begin(), countries.end(), compareCountries);

    if (!countries.empty()) {
        cout << countries[0].first;
    }

    return 0;
}