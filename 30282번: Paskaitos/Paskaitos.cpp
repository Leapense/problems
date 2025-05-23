#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Lecture {
    int day, start, end;
};

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    vector<Lecture> lectures(10);
    for (int i = 0; i < 10; i++) {
        int s, hpr, mpr, hpb, mpb;
        cin >> s >> hpr >> mpr >> hpb >> mpb;
        lectures[i].day = s;
        lectures[i].start = hpr * 60 + mpr;
        lectures[i].end = hpb * 60 + mpb;
    }
    
    bool overlap = false;

    int a = -1, b = -1;

    for (int i = 0; i < 10 && !overlap; i++) {
        for (int j = i + 1; j < 10 && !overlap; j++) {
            if (lectures[i].day == lectures[j].day) {
                if (!(lectures[i].end <= lectures[j].start || lectures[j].end <= lectures[i].start)) {
                    overlap = true;
                    a = i + 1;
                    b = j + 1;
                }
            }
        }
    }

    if (overlap) {
        cout << "NE\n" << a << " " << b;
    } else {
        long long total = 0;
        for (auto &lec : lectures) {
            total += (lec.end - lec.start);
        }

        long long hours = total / 60;
        long long minutes = total % 60;

        cout << "TAIP\n" << hours << " " << minutes;
    }

    return 0;
}