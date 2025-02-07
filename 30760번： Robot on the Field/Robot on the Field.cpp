#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int targetX, targetY;
    cin >> targetX >> targetY;

    vector<int> posL, posR, posU, posD;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == 'L')
            posL.push_back(i + 1);
        else if (c == 'R')
            posR.push_back(i + 1);
        else if (c == 'U')
            posU.push_back(i + 1);
        else if (c == 'D')
            posD.push_back(i + 1);
    }

    int totalL = posL.size(), totalR = posR.size();
    int totalU = posU.size(), totalD = posD.size();

    int lowerL = max(0, -targetX);
    int upperL = min(totalL, totalR - targetX);
    if (lowerL > upperL)
    {
        cout << -1;
        return 0;
    }

    int allowedL = lowerL;
    int allowedR = allowedL + targetX;
    if (allowedR < 0 || allowedR > totalR)
    {
        cout << -1;
        return 0;
    }

    int lowerD = max(0, -targetY);
    int upperD = min(totalD, totalU - targetY);
    if (lowerD > upperD)
    {
        cout << -1;
        return 0;
    }

    int allowedD = lowerD;
    int allowedU = allowedD + targetY;

    if (allowedU < 0 || allowedU > totalU)
    {
        cout << -1;
        return 0;
    }

    auto getBreakTime = [&](const vector<int> &positions, int allowedCount) -> int
    {
        int total = positions.size();
        if (allowedCount == 0)
            return 0;
        if (allowedCount < total)
            return positions[allowedCount - 1];
        return n;
    };

    int breakL = getBreakTime(posL, allowedL);
    int breakU = getBreakTime(posU, allowedU);
    int breakR = getBreakTime(posR, allowedR);
    int breakD = getBreakTime(posD, allowedD);

    cout << breakL << " " << breakU << " " << breakR << " " << breakD;

    return 0;
}