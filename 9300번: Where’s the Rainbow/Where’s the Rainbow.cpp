#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; ++case_num) {
        double h, theta;
        cin >> h >> theta;
        
        double theta_rad = theta * M_PI / 180.0;
        double tan_theta = tan(theta_rad);

        cout << "Case " << case_num << ": ";
        if (tan_theta < 1e-8) {
            cout << "Infinity\n";
        } else {
            double d = h * fabs(1.0 - 1.0 / tan_theta);
            if (d > 1e15) {
                cout << "Infinity\n";
            } else {
                printf("%.5f\n", d);
            }
        }
    }

    return 0;
}