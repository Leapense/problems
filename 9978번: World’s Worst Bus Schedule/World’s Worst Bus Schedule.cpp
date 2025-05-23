#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        string startLine;
        if (!getline(cin, startLine)) break;
        if (startLine == "ENDOFINPUT") break;
        if (startLine.size() == 0) continue;

        // startLine is "START N"
        if (startLine.substr(0, 5) != "START") continue;
        int N;
        {
            stringstream ss(startLine);
            string dummy;
            ss >> dummy >> N;
        }

        vector<vector<int>> buses(N);
        for (int i = 0; i < N; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int d;
            while (ss >> d) {
                buses[i].push_back(d);
            }
        }

        string arrivalLine;
        getline(cin, arrivalLine);
        int arrivalTime;
        {
            stringstream ss(arrivalLine);
            ss >> arrivalTime;
        }

        string endLine;
        getline(cin, endLine); 

        int minWait = 1000000000;
        for (int i = 0; i < N; i++) {
            const vector<int> &routes = buses[i];
            int cycle = 0;
            for (auto d : routes) cycle += d;

            // partial sums including start=0
            vector<int> partial;
            partial.push_back(0);
            int sum = 0;
            for (auto d : routes) {
                sum += d;
                partial.push_back(sum);
            }

            int r = arrivalTime % cycle;
            int waitForThisBus = 1000000000;
            for (auto ps : partial) {
                if (ps >= r) {
                    int wait = ps - r;
                    waitForThisBus = min(waitForThisBus, wait);
                } else {
                    int wait = (cycle - r) + ps;
                    waitForThisBus = min(waitForThisBus, wait);
                }
            }
            minWait = min(minWait, waitForThisBus);
        }

        cout << minWait << "\n";
    }

    return 0;
}