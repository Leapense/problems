#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Member {
    string name;
    int max_reverse_streak;
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Member> members;

    for (int i = 0; i < N; ++i) {
        vector<char> activities(M);
        for(int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            activities[j] = c;
        }
        string name;
        cin >> name;

        int current = 0;
        int max_streak = 0;

        for (int j = 0; j < M; ++j) {
            if (activities[j] == '.') {
                current++;
                if (current > max_streak) {
                    max_streak = current;
                }
            } else {
                current = 0;
            }
        }

        Member m;
        m.name = name;
        m.max_reverse_streak = max_streak;
        members.push_back(m);
    }

    set<int> unique_streaks;
    for(auto &m : members) {
        unique_streaks.insert(m.max_reverse_streak);
    }

    cout << unique_streaks.size() << "\n";

    for (auto &m : members) {
        cout << m.max_reverse_streak << " " << m.name << "\n";
    }

    return 0;
}