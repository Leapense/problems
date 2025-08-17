#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct StationRef {
    const char* name;
    double dist;
};

static const StationRef STATIONS[] = {
    {"Seoul", 0.0},
    {"Yeongdeungpo", 9.1},
    {"Anyang", 23.9},
    {"Suwon", 41.5},
    {"Osan", 56.5},
    {"Seojeongri", 66.5},
    {"Pyeongtaek", 75.0},
    {"Seonghwan", 84.4},
    {"Cheonan", 96.6},
    {"Sojeongni", 107.4},
    {"Jeonui", 114.9},
    {"Jochiwon", 129.3},
    {"Bugang", 139.8},
    {"Sintanjin", 151.9},
    {"Daejeon", 166.3},
    {"Okcheon", 182.5},
    {"Iwon", 190.8},
    {"Jitan", 196.4},
    {"Simcheon", 200.8},
    {"Gakgye", 204.6},
    {"Yeongdong", 211.6},
    {"Hwanggan", 226.2},
    {"Chupungyeong", 234.7},
    {"Gimcheon", 253.8},
    {"Gumi", 276.7},
    {"Sagok", 281.3},
    {"Yangmok", 289.5},
    {"Waegwan", 296.0},
    {"Sindong", 305.9},
    {"Daegu", 323.1},
    {"Dongdaegu", 326.3},
    {"Gyeongsan", 338.6},
    {"Namseonghyeon", 353.1},
    {"Cheongdo", 361.8},
    {"Sangdong", 372.2},
    {"Miryang", 381.6},
    {"Samnangjin", 394.1},
    {"Wondong", 403.2},
    {"Mulgeum", 412.4},
    {"Hwamyeong", 421.8},
    {"Gupo", 425.2},
    {"Sasang", 430.3},
    {"Busan", 441.7}
};

static const int DAY_MINUTES = 1440;
static const int STN_CNT = (int)(sizeof(STATIONS) / sizeof(STATIONS[0]));

string fmtTime(int absMin) {
    int t = ((absMin % DAY_MINUTES) + DAY_MINUTES) % DAY_MINUTES;
    int hh = t / 60;
    int mm = t % 60;
    char buf[8];
    snprintf(buf, sizeof(buf), "%02d:%02d", hh, mm);
    return string(buf);
}

vector<int> pickContiguousIndices(int n) {
    int start = rnd.next(0, STN_CNT - n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = start + i;
    return idx;
}

vector<int> pickIncreasingIndices(int n) {
    vector<int> all(STN_CNT);
    iota(all.begin(), all.end(), 0);
    shuffle(all.begin(), all.end());
    all.resize(n);
    sort(all.begin(), all.end());
    return all;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    long long seed = atoll(argv[1]);
    rnd.setSeed(seed);

    string mode = (argc >= 3 ? string(argv[2]) : string("random"));
    int n = (argc >= 4 ? atoi(argv[3]) : -1);
    int q = (argc >= 5 ? atoi(argv[4]) : -1);

    if (n < 2 || n > STN_CNT) {
        if (mode == "max") n = STN_CNT;
        else if (mode == "overnight") n = rnd.next(5, 12);
        else if (mode == "invalid") n = rnd.next(6, 16);
        else n = rnd.next(5, 15);
    }
    if (q < 1) {
        if (mode == "max") q = 300;
        else if (mode == "invalid") q = 40;
        else q = rnd.next(15, 40);
    }
    n = max(2, min(n, STN_CNT));
    q = max(1, q);

    bool contiguous = true;
    if (mode == "random") contiguous = (rnd.next(0, 1) == 0);
    else if (mode == "basic" || mode == "overnight" || mode == "max") contiguous = true;
    else if (mode == "invalid") contiguous = true;
    else contiguous = false;

    vector<int> idx = contiguous ? pickContiguousIndices(n) : pickIncreasingIndices(n);
    vector<long long> arrAbs(n, -1), depAbs(n, -1);
    int startAbs = 0;
    if (mode == "basic") {
        startAbs = rnd.next(5 * 60, 10 * 60);
    } else if (mode == "overnight") {
        startAbs = rnd.next(23 * 60 - 30, 23 * 60 + 50);
        startAbs = max(0, min(startAbs, DAY_MINUTES - 1));
    } else if (mode == "max") {
        startAbs = rnd.next(0, DAY_MINUTES - 1);
    } else {
        startAbs = rnd.next(0, DAY_MINUTES - 1);
    }

    depAbs[0] = startAbs;
    vector<int> travel(n - 1, 0);
    vector<int> dwell(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int tmin = 0, tmax = 0;
        if (mode == "basic") {
            tmin = 6;
            tmax = 18;
        } else if (mode == "overnight") {
            if (i == 0) {
                int toMid = DAY_MINUTES - (depAbs[0] % DAY_MINUTES);
                tmin = max(1, toMid + 5);
                tmax = toMid + 90;
            } else {
                tmin = 5;
                tmax = 20;
            }
        } else if (mode == "max") {
            tmin = 2;
            tmax = 20;
        } else {
            tmin = 4;
            tmax = 30;
        }
        travel[i] = rnd.next(tmin, tmax);
    }
    for (int i = 1; i < n - 1; i++) {
        int dmin = 0, dmax = 0;
        if (mode == "basic") { dmin = 1; dmax = 4; }
        else if (mode == "overnight") { dmin = 1; dmax = 6; }
        else if (mode == "max") { dmin = 0; dmax = 3; }
        else { dmin = 0; dmax = 5; }
        dwell[i] = rnd.next(dmin, dmax);
    }

    long long cur = depAbs[0];
    for (int i = 1; i < n; i++) {
        arrAbs[i] = cur + travel[i - 1];
        cur = arrAbs[i];
        if (i < n - 1) {
            depAbs[i] = cur + dwell[i];
            cur = depAbs[i];
        }
    }

    vector<string> arrStr(n), depStr(n);
    bool firstArrMissing = true;
    bool lastDepMissing = true;
    if (mode == "max") { firstArrMissing = true; lastDepMissing = true; }
    else if (mode == "overnight") { firstArrMissing = true; lastDepMissing = true; }
    else if (mode == "basic" || mode == "random") { firstArrMissing = true; lastDepMissing = true; }
    else if (mode == "invalid") { firstArrMissing = true; lastDepMissing = true; }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            arrStr[i] = firstArrMissing ? "-:-" : fmtTime((int)arrAbs[i]);
            depStr[i] = fmtTime((int)depAbs[i]);
        } else if (i == n - 1) {
            arrStr[i] = fmtTime((int)arrAbs[i]);
            depStr[i] = lastDepMissing ? "-:-" : fmtTime((int)(arrAbs[i] + 1)); // not used anyway
        } else {
            arrStr[i] = fmtTime((int)arrAbs[i]);
            depStr[i] = fmtTime((int)depAbs[i]);
        }
    }

    cout << n << " " << q << "\n";
    for (int i = 0; i < n; i++) {
        cout << STATIONS[idx[i]].name << " " << arrStr[i] << " " << depStr[i] << "\n";
    }

    vector<string> usedNames(n);
    for (int i = 0; i < n; i++) usedNames[i] = STATIONS[idx[i]].name;
    set<string> usedSet(usedNames.begin(), usedNames.end());
    vector<string> unusedNames;
    for (int i = 0; i < STN_CNT; i++) {
        if (!usedSet.count(STATIONS[i].name)) unusedNames.emplace_back(STATIONS[i].name);
    }

    auto makeValidPair = [&]() -> pair<string,string> {
        int i1 = rnd.next(0, n - 2);
        int i2 = rnd.next(i1 + 1, n - 1);
        // ensure dep exists for i1 and arr exists for i2
        if (i1 == n - 1) i1 = n - 2;
        if (i2 == 0) i2 = 1;
        return {usedNames[i1], usedNames[i2]};
    };

    auto makeReversedPair = [&]() -> pair<string,string> {
        // ensure dep for first (i1 <= n-2) and arr for second (i2 >= 1)
        int i1 = rnd.next(1, n - 2); // avoid n-1 and 0
        int i2 = rnd.next(0, i1 - 1);
        if (i2 == 0) i2 = 1; // ensure arr exists
        return {usedNames[i1], usedNames[i2]};
    };

    auto makeUnknownPair = [&]() -> pair<string,string> {
        string a, b;
        if (!unusedNames.empty()) {
            a = unusedNames[rnd.next(0, (int)unusedNames.size() - 1)];
        } else {
            a = "NonexistentStation";
        }
        if (!unusedNames.empty()) {
            b = unusedNames[rnd.next(0, (int)unusedNames.size() - 1)];
        } else {
            b = "AnotherFakeStation";
        }
        return {a, b};
    };

    if (mode == "invalid") {
        for (int i = 0; i < q; i++) {
            int type = rnd.next(0, 2); // 0: valid, 1: reversed, 2: unknown
            pair<string,string> p;
            if (type == 0) p = makeValidPair();
            else if (type == 1) p = makeReversedPair();
            else p = makeUnknownPair();
            cout << p.first << " " << p.second << "\n";
        }
    } else {
        // Mostly valid; in random mode, sprinkle a few unknown pairs
        int unknownCount = 0;
        if (mode == "random") unknownCount = q / 10; // ~10%
        else unknownCount = 0;

        for (int i = 0; i < q; i++) {
            pair<string,string> p;
            if (i < unknownCount) p = makeUnknownPair();
            else p = makeValidPair();
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}