#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Date {
    int year, month, day;
};

Date jdn_to_gregorian(ll jdn){
    ll a = jdn + 32044;
    ll b = (4*a +3)/146097;
    ll c = a - (146097*b)/4;
    ll d = (4*c +3)/1461;
    ll e = c - (1461*d)/4;
    ll m = (5*e +2)/153;
    int day = e - (153*m +2)/5 +1;
    int month = m +3 - 12*(m/10);
    int year = 100*b + d -4800 + m/10;
    return Date{(int)year, (int)month, (int)day};
}

ll julian_to_jdn(int year, int month, int day){
    ll a = (14 - month) / 12;
    ll y = year + 4800 - a;
    ll m = month + 12*a -3;
    ll JDN = day + (153*m +2)/5 + 365*y + y/4 -32083;
    return JDN;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        int year, month, day;
        sscanf(line.c_str(), "%d-%d-%d", &year, &month, &day);

        int D;
        if (year < 1700) {
            D = 10;
        } else {
            D =10 + (year /100) - (year /400) -12;
            if(year %100 ==0 && year %400 !=0 && month <3){
                D -=1;
            }
        }

        ll JDN_julian = julian_to_jdn(year, month, day);
        ll JDN_gregorian = JDN_julian + D + 1;
        Date gregorian = jdn_to_gregorian(JDN_gregorian);
        printf("%04d-%02d-%02d\n", gregorian.year, gregorian.month, gregorian.day);
    }

    return 0;
}