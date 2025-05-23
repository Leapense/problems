#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> A;
int count_valid = 0;

bool visited[8] = {false};

void backtrack(int day, int current_weight) {
    if (day == N) {
        count_valid++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int new_weight = current_weight + A[i] - K;

            if (new_weight >= 500) {
                backtrack(day + 1, new_weight);
            }

            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    backtrack(0, 500);

    cout << count_valid << endl;
    return 0;
}