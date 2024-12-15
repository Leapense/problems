#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    string startLine;
    while (getline(cin, startLine) && startLine != "ENDOFINPUT")
    {
        int numBuses;
        sscanf(startLine.c_str(), "START %d", &numBuses);

        vector<vector<int>> routes(numBuses);
        for (int i = 0; i < numBuses; ++i) {
            string routeLine;
            getline(cin, routeLine);

            int routeDuration;
            char* str = const_cast<char*>(routeLine.c_str());

            while(sscanf(str, "%d", &routeDuration) == 1) {
                routes[i].push_back(routeDuration);
                while(*str && isdigit(*str)) str++;
                while(*str && isspace(*str)) str++;
            }
        }

        int arrivalTime;
        cin >> arrivalTime;
        cin.ignore();

        int minWaitTime = INT_MAX;

        for (const auto& route : routes) {
            int currentTime = 0;
            while (true) {
                for (int duration : route) {
                    currentTime += duration;
                    if (currentTime >= arrivalTime) {
                        minWaitTime = min(minWaitTime, currentTime - arrivalTime);
                        goto next_bus;
                    }
                }
            }
            next_bus:;
        }

        cout << minWaitTime << "\n";
        string endLine;
        getline(cin, endLine);
    }

    return 0;
}