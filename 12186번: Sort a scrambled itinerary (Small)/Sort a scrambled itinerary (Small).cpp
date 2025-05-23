#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int test = 1; test <= T; test++) {
        int N;
        cin >> N;
        cin.ignore();
        map<string, string> flights;
        set<string> destinations;
        for(int i = 0; i < N; i++) {
            string src, dest;
            getline(cin, src);
            getline(cin, dest);
            flights[src] = dest;
            destinations.insert(dest);
        }

        string start;
        for (auto& pair : flights) {
            if (destinations.find(pair.first) == destinations.end()) {
                start = pair.first;
                break;
            }
        }

        string itinerary;
        string current = start;
        for (int i = 0; i < N; i++) {
            itinerary += current + "-" + flights[current];
            if (i != N - 1) {
                itinerary += " ";
            }

            current = flights[current];
        }

        cout << "Case #" << test << ": " << itinerary << endl;
    }

    return 0;
}