//=====================================================================
//   15183번:    Musical Chairs                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/15183  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> initial(N);

    for (auto &s : initial) cin >> s;
    vector<string> seating = initial;

    int R;
    cin >> R;

    while (R--) {
        int S, M;
        cin >> S >> M;

        int size = seating.size();
        int steps = M % size;

        if (steps != 0) {
            int rotate_steps = (size - steps) % size;
            rotate(seating.begin(), seating.begin() + rotate_steps, seating.end());
        }
        string eliminated = seating[S - 1];

        cout << eliminated << " has been eliminated.\n";
        seating.erase(seating.begin() + (S - 1));
    }

    if (seating.size() == 1) {
        cout << seating[0] << " has won.\n";
    } else {
        cout << "Players left are";
        vector<string> remaining;

        unordered_set<string> rem_set(seating.begin(), seating.end());

        for (auto &s : initial) {
            if (rem_set.find(s) != rem_set.end()) {
                remaining.push_back(s);
            }
        }

        for (auto &s : remaining) {
            cout << " " << s;
        }

        cout << ".\n";
    }

    return 0;
}
