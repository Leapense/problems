#include <bits/stdc++.h>

using namespace std;

int timeToSeconds(const string &timeStr)
{
    int minutes, seconds;
    char colon; // I Love GD COLON.
    istringstream iss(timeStr);
    iss >> minutes >> colon >> seconds;
    return minutes * 60 + seconds;
}

string formatTime(int totalSeconds)
{
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    ostringstream oss;
    oss << minutes << ":" << setw(2) << setfill('0') << seconds;
    return oss.str();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int gameDuration = 32 * 60;

    int homeScore = 0, awayScore = 0;
    int homeLeadTime = 0, awayLeadTime = 0;
    int prevTime = 0;

    for (int i = 0; i < n; i++)
    {
        char team;
        int points;
        string timeStr;
        cin >> team >> points >> timeStr;

        int eventTime = timeToSeconds(timeStr);
        int deltaTime = eventTime - prevTime;

        if (homeScore > awayScore)
            homeLeadTime += deltaTime;
        else if (awayScore > homeScore)
            awayLeadTime += deltaTime;

        if (team == 'H')
            homeScore += points;
        else
            awayScore += points;

        prevTime = eventTime;
    }

    int deltaTime = gameDuration - prevTime;
    if (homeScore > awayScore)
        homeLeadTime += deltaTime;
    else if (awayScore > homeScore)
        awayLeadTime += deltaTime;

    char winner = (homeScore > awayScore) ? 'H' : 'A';

    cout << winner << " " << formatTime(homeLeadTime) << " " << formatTime(awayLeadTime) << "\n";

    return 0;
}