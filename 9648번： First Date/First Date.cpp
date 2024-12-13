#include <bits/stdc++.h>
using namespace std;

// 줄리안 날짜를 JDN으로 변환 (줄리안 달력)
int julian_to_jdn(int Y, int M, int D) {
    int a = (14 - M) / 12;
    int y = Y + 4800 - a;
    int m = M + 12*a - 3;
    return D + (153*m + 2)/5 + 365*y + y/4 - 32083;
}

// JDN을 그레고리안 날짜로 변환
void jdn_to_gregorian(int J, int &Y, int &M, int &D) {
    int a = J + 32044;
    int b = (4*a+3)/146097;
    int c = a - (146097*b)/4;
    int d = (4*c+3)/1461;
    int e = c - (1461*d)/4;
    int m = (5*e+2)/153;
    D = e - (153*m+2)/5 + 1;
    M = m + 3 - 12*(m/10);
    Y = 100*b + d - 4800 + m/10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string date;
    while (true) {
        if (! (cin >> date)) break;
        if (date.empty()) break;

        int Y,M,D;
        {
            char c;
            stringstream ss(date);
            ss >> Y >> c >> M >> c >> D;
        }

        // 마지막 줄리안 날짜의 다음 날 JDN 구하기
        int JDN_jul_last = julian_to_jdn(Y,M,D);
        int JDN_next = JDN_jul_last + 1; // 다음 날 JDN

        // 다음 날 JDN을 그레고리안 날짜로 변환
        int gY,gM,gD;
        jdn_to_gregorian(JDN_next, gY, gM, gD);

        cout << setw(4) << setfill('0') << gY << "-" 
             << setw(2) << setfill('0') << gM << "-"
             << setw(2) << setfill('0') << gD << "\n";
    }

    return 0;
}
