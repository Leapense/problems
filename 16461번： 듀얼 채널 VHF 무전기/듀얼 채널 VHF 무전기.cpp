#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        double fa, fb, target;
        char cur;
        cin >> fa >> fb >> cur >> target;
        int fa_int = round(fa * 1000);
        int fb_int = round(fb * 1000);
        int target_int = round(target * 1000);
        int best = 1e9;
        for (int ch = 0; ch < 2; ch++)
        {
            int switchCost = 0;
            int freq;
            if (ch == 0)
            {
                freq = fa_int;
                if (cur != 'A')
                    switchCost = 1;
            }
            else
            {
                freq = fb_int;
                if (cur != 'B')
                    switchCost = 1;
            }
            int candidate = 1e9;
            if (freq == target_int)
                candidate = min(candidate, switchCost);
            candidate = min(candidate, switchCost + 6);
            {
                int cnt = 0;
                int curFreq = freq;
                bool found = false;
                for (int i = 0; i <= 200; i++)
                {
                    if (curFreq == target_int)
                    {
                        found = true;
                        break;
                    }
                    if (curFreq <= 145980)
                        curFreq += 20;
                    else
                        curFreq = 144000;
                    cnt++;
                }
                if (found)
                    candidate = min(candidate, switchCost + cnt);
            }
            {
                int cnt = 0;
                int curFreq = freq;
                bool found = false;
                for (int i = 0; i <= 200; i++)
                {
                    if (curFreq == target_int)
                    {
                        found = true;
                        break;
                    }
                    if (curFreq >= 144020)
                        curFreq -= 20;
                    else
                        curFreq = 146000;
                    cnt++;
                }
                if (found)
                    candidate = min(candidate, switchCost + cnt);
            }
            best = min(best, candidate);
        }
        cout << best << "\n";
    }
    return 0;
}
