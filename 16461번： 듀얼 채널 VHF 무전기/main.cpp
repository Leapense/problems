#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

constexpr double STEP = 0.020;
constexpr double MIN_FREQ = 144.000;
constexpr double MAX_FREQ = 146.000;

int upDownButtonPresses(double current, double target)
{
    int diff = round((target - current) / STEP);
    if (diff < 0)
        diff += round((MAX_FREQ - MIN_FREQ) / STEP) + 1;
    return diff;
}

int downUpButtonPresses(double current, double target)
{
    int diff = round((current - target) / STEP);
    if (diff < 0)
        diff += round((MAX_FREQ - MIN_FREQ) / STEP) + 1;
    return diff;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        double freqA, freqB, target;

        char currentChannel;
        cin >> freqA >> freqB >> currentChannel >> target;

        double currentFreq = (currentChannel == 'A') ? freqA : freqB;
        double otherFreq = (currentChannel == 'A') ? freqB : freqA;

        if (currentFreq == target)
        {
            cout << 0 << "\n";
            continue;
        }

        int pressDirect = 6;
        int pressUp = upDownButtonPresses(currentFreq, target);
        int pressDown = downUpButtonPresses(currentFreq, target);
        int minPress = min({pressDirect, pressUp, pressDown});
        int switchPress = 1;

        if (otherFreq == target)
        {
            minPress = min(minPress, switchPress);
        }
        else
        {
            int otherPressDirect = 6;
            int otherPressUp = upDownButtonPresses(otherFreq, target);
            int otherPressDown = downUpButtonPresses(otherFreq, target);
            int otherMinPress = min({otherPressDirect, otherPressUp, otherPressDown}) + switchPress;

            minPress = min(minPress, otherMinPress);
        }

        cout << minPress << "\n";
    }

    return 0;
}