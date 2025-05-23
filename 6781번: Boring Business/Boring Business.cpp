#include <bits/stdc++.h>
using namespace std;

string travel(char direction, string position, int magnitude, vector<string> &collect) {
    int currentX = stoi(position.substr(0, position.find(" ")));
    int currentY = stoi(position.substr(position.find(" ") + 1));

    bool safe = true;
    switch (direction) {
        case 'l':
            for (int i = 0; i < magnitude; i++) {
                currentX -= 1;
                if (find(collect.begin(), collect.end(), to_string(currentX) + " " + to_string(currentY)) != collect.end()) {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                    safe = false;
                } else {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                }
            }
            break;
        case 'r':
            for (int i = 0; i < magnitude; i++) {
                currentX += 1;
                if (find(collect.begin(), collect.end(), to_string(currentX) + " " + to_string(currentY)) != collect.end()) {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                    safe = false;
                } else {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                }
            }
            break;
        case 'd':
            for (int i = 0; i < magnitude; i++) {
                currentY -= 1;
                if (find(collect.begin(), collect.end(), to_string(currentX) + " " + to_string(currentY)) != collect.end()) {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                    safe = false;
                } else {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                }
            }
            break;
        case 'u':
            for (int i = 0; i < magnitude; i++) {
                currentY += 1;
                if (find(collect.begin(), collect.end(), to_string(currentX) + " " + to_string(currentY)) != collect.end()) {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                    safe = false;
                } else {
                    collect.push_back(to_string(currentX) + " " + to_string(currentY));
                }
            }
            break;
    }
    return (safe) ? "safe" : "DANGER";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> traversed;
    string start = "0 -1";
    traversed.push_back(start);
    
    travel('d', start, 2, traversed);
    travel('r', traversed.back(), 3, traversed);
    travel('d', traversed.back(), 2, traversed);
    travel('r', traversed.back(), 2, traversed);
    travel('u', traversed.back(), 2, traversed);
    travel('r', traversed.back(), 2, traversed);
    travel('d', traversed.back(), 4, traversed);
    travel('l', traversed.back(), 8, traversed);
    travel('u', traversed.back(), 2, traversed);

    string input;
    while (getline(cin, input)) {
        if (input == "q 0") break;

        stringstream ss(input);
        char direction;
        int magnitude;
        ss >> direction >> magnitude;

        string condition = travel(direction, traversed.back(), magnitude, traversed);
        string end = traversed.back();
        stringstream endStream(end);
        int endX, endY;
        endStream >> endX >> endY;
        
        cout << endX << " " << endY << " " << condition << "\n";
        if (condition == "DANGER") break;
    }

    return 0;
}