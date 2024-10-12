#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Code {
    int label;
    int president_points;
    int member_points;
    int total_points;
};

bool compareCodes(const Code& a, const Code& b) {
    if (a.total_points != b.total_points) {
        return a.total_points > b.total_points;
    } else {
        return a.member_points > b.member_points;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Code> codes(n);

    for (int i = 0; i < n; ++i) {
        int label;
        cin >> label;

        codes[label - 1].label = label;
        codes[label - 1].president_points = n - i;
    }

    vector<pair<int, int>> votes(n);

    for (int i = 0; i < n; ++i) {
        cin >> votes[i].first;
        votes[i].second = i + 1;
    }

    sort(votes.rbegin(), votes.rend());

    for (int i = 0; i < n; ++i) {
        codes[votes[i].second - 1].member_points = n - i;
    }

    for (int i = 0; i < n; ++i) {
        codes[i].total_points = codes[i].president_points + codes[i].member_points;
    }

    sort(codes.begin(), codes.end(), compareCodes);

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". Kod" << setfill('0') << setw(2) << codes[i].label << " (" << codes[i].total_points << ")\n";
    }

    return 0;
}