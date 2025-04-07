#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> answer(N, -1);
    answer[N - 1] = -1;

    for (int i = N - 2; i >= 0; i--) {
        if (A[i] != A[i + 1]) {
            answer[i] = i + 1;
        } else {
            answer[i] = answer[i + 1];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
