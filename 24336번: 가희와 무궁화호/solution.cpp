#include <bits/stdc++.h>
using namespace std;

struct Stop {
    string name;
    int arrTod;
    int depTod;
    int arrAbs;
    int depAbs;
};

static constexpr int DayMinutes = 1440;

static int parseTimeTod(const string& s) {
    if (s.size() == 3 && s[0] == '-' && s[1] == ':' && s[2] == '-') return -1;
    int hh = 0, mm = 0;
    size_t pos = s.find(':');
    if (pos == string::npos) return -1;
    hh = stoi(s.substr(0, pos));
    mm = stoi(s.substr(pos + 1));
    return hh * 60 + mm;
}

static int computeNextAbs(int prevAbs, int nextTod) {
    if (nextTod < 0) return -1;
    if (prevAbs < 0) return nextTod;
    int prevTod = prevAbs % DayMinutes;
    int base = prevAbs - prevTod;
    int candidate = base + nextTod;
    if (!(prevTod < nextTod)) candidate += DayMinutes;
    return candidate;
}

static unordered_map<string, double> buildDistanceMap() {
    unordered_map<string, double> m;
    m.reserve(64);
    m["Seoul"] = 0.0;
    m["Yeongdeungpo"] = 9.1;
    m["Anyang"] = 23.9;
    m["Suwon"] = 41.5;
    m["Osan"] = 56.5;
    m["Seojeongri"] = 66.5;
    m["Pyeongtaek"] = 75.0;
    m["Seonghwan"] = 84.4;
    m["Cheonan"] = 96.6;
    m["Sojeongni"] = 107.4;
    m["Jeonui"] = 114.9;
    m["Jochiwon"] = 129.3;
    m["Bugang"] = 139.8;
    m["Sintanjin"] = 151.9;
    m["Daejeon"] = 166.3;
    m["Okcheon"] = 182.5;
    m["Iwon"] = 190.8;
    m["Jitan"] = 196.4;
    m["Simcheon"] = 200.8;
    m["Gakgye"] = 204.6;
    m["Yeongdong"] = 211.6;
    m["Hwanggan"] = 226.2;
    m["Chupungnyeong"] = 234.7;
    m["Gimcheon"] = 253.8;
    m["Gumi"] = 276.7;
    m["Sagok"] = 281.3;
    m["Yangmok"] = 289.5;
    m["Waegwan"] = 296.0;
    m["Sindong"] = 305.9;
    m["Daegu"] = 323.1;
    m["Dongdaegu"] = 326.3;
    m["Gyeongsan"] = 338.6;
    m["Namseonghyeon"] = 353.1;
    m["Cheongdo"] = 361.8;
    m["Sangdong"] = 372.2;
    m["Miryang"] = 381.6;
    m["Samnangjin"] = 394.1;
    m["Wondong"] = 403.2;
    m["Mulgeum"] = 412.4;
    m["Hwamyeong"] = 421.8;
    m["Gupo"] = 425.2;
    m["Sasang"] = 430.3;
    m["Busan"] = 441.7;
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, q = 0;
    if (!(cin >> n >> q)) return 0;

    vector<Stop> stops(n);
    for (int i = 0; i < n; i++) {
        string arr, dep;
        cin >> stops[i].name >> arr >> dep;
        stops[i].arrTod = parseTimeTod(arr);
        stops[i].depTod = parseTimeTod(dep);
        stops[i].arrAbs = -1;
        stops[i].depAbs = -1;
    }

    int prevAbs = -1;
    if (n > 0) {
        stops[0].depAbs = computeNextAbs(prevAbs, stops[0].depTod);
        prevAbs = stops[0].depAbs;
    }

    for (int i = 1; i < n; i++) {
        stops[i].arrAbs = computeNextAbs(prevAbs, stops[i]. arrTod);
        prevAbs = stops[i].arrAbs;
        if (i < n - 1) {
            stops[i].depAbs = computeNextAbs(prevAbs, stops[i].depTod);
            prevAbs = stops[i].depAbs;
        }
    }

    unordered_map<string, int> idx;
    idx.reserve(n * 2);
    for (int i = 0; i < n; i++) idx[stops[i].name] = i;

    auto dist = buildDistanceMap();
    cout.setf(std::ios::fixed);
    cout << setprecision(10);

    for (int i = 0; i < q; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        auto it1 = idx.find(s1);
        auto it2 = idx.find(s2);
        if (it1 == idx.end() || it2 == idx.end()) {
            cout << "0.0000000000\n";
            continue;
        }
        int i1 = it1->second;
        int i2 = it2->second;
        int timeMin = stops[i2].arrAbs - stops[i1].depAbs;
        auto d1it = dist.find(s1);
        auto d2it = dist.find(s2);
        if (d1it == dist.end() || d2it == dist.end()) {
            cout << "0.0000000000\n";
            continue;
        }
        double distanceKm = fabs(d2it->second - d1it->second);
        double speed = distanceKm * 60.0 / static_cast<double>(timeMin);
        cout << speed << "\n";
    }

    return 0;
}