#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double X1, X2;
    cin >> X1 >> X2;
    int n1;
    cin >> n1;

    vector<int> t1(n1);

    for (int i = 0; i < n1; i++)
    {
        cin >> t1[i];
    }

    int n2;
    cin >> n2;
    vector<int> t2(n2);

    for (int i = 0; i < n2; i++)
    {
        cin >> t2[i];
    }

    double pos1 = X1, pos2 = X2;
    int idx1 = 0, idx2 = 0;
    int curTime = 0;
    int speed1 = 0, speed2 = 0;
    bool car1Trailing;
    if (X1 + 5 <= X2)
    {
        car1Trailing = true;
    }
    else
    {
        car1Trailing = false;
    }

    while (true)
    {
        int nextTime = 1000001;
        if (idx1 < n1)
            nextTime = min(nextTime, t1[idx1]);
        if (idx2 < n2)
            nextTime = min(nextTime, t2[idx2]);
        int dt = nextTime - curTime;
        double trailingPos, leadingPos;

        int trailingSpeed, leadingSpeed;
        if (car1Trailing)
        {
            trailingPos = pos1;
            trailingSpeed = speed1;
            leadingPos = pos2;
            leadingSpeed = speed2;
        }
        else
        {
            trailingPos = pos2;
            trailingSpeed = speed2;
            leadingPos = pos1;
            leadingSpeed = speed1;
        }

        if (trailingSpeed > leadingSpeed)
        {
            double gap = leadingPos - trailingPos - 4.4;
            if (gap <= 0)
            {
                cout << "bumper tap at time " << curTime << endl;
                return 0;
            }

            double rel = trailingSpeed - leadingSpeed;
            double dtCollision = gap / rel;
            if (dtCollision <= dt)
            {
                int ans = curTime + (int)ceil(dtCollision);
                cout << "bumper tap at time " << ans << endl;
                return 0;
            }
        }

        pos1 += speed1 * dt;
        pos2 += speed2 * dt;
        curTime = nextTime;
        if (curTime == 1000001)
            break;
        if (idx1 < n1 && curTime == t1[idx1])
        {
            speed1 = 1 - speed1;
            idx1++;
        }
        if (idx2 < n2 && curTime == t2[idx2])
        {
            speed2 = 1 - speed2;
            idx2++;
        }
    }

    if (speed1 > speed2 || speed2 > speed1)
    {
        int dtCollision;
        if (car1Trailing)
        {
            if (speed1 > speed2)
            {
                double gap = pos2 - pos1 - 4.4;

                if (gap <= 0)
                {
                    cout << "bumper tap at time " << curTime << endl;
                    return 0;
                }

                dtCollision = (int)ceil(gap);
                cout << "bumper tap at time " << curTime + dtCollision << "\n";
                return 0;
            }
        }
        else
        {
            if (speed2 > speed1)
            {
                double gap = pos1 - pos2 - 4.4;
                if (gap <= 0)
                {
                    cout << "bumper tap at time " << curTime << "\n";
                    return 0;
                }
                dtCollision = (int)ceil(gap);
                cout << "bumper tap at time " << curTime + dtCollision << "\n";
                return 0;
            }
        }
    }

    cout << "safe and sound" << "\n";

    return 0;
}