#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Toy {
    string name;
    int count;
};

bool compare(const Toy &a, const Toy &b) {
    if (a.count == b.count) {
        return a.name < b.name;
    }

    return a.count > b.count;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        map<string, int> toy_counts;

        for(int i = 0; i < N; ++i) {
            string toy_name;
            int count;
            cin >> toy_name >> count;
            toy_counts[toy_name] += count;
        }

        vector<Toy> toys;

        for (const auto &entry : toy_counts) {
            toys.push_back({entry.first, entry.second});
        }

        sort(toys.begin(), toys.end(), compare);

        cout << toys.size() << endl;

        for (const auto &toy : toys) {
            cout << toy.name << " " << toy.count << endl;
        }
    }

    return 0;
}