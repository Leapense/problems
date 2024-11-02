#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> matrix(N);

        for (int i = 0; i < N; i++) {
            cin >> matrix[i];
            while(matrix[i].size() < M) matrix[i] += '.';
        }

        vector<vector<bool>> visited(N, vector<bool>(M, false));

        int line_count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && matrix[i][j] != '.') {
                    char current = matrix[i][j];

                    int di = 0, dj = 0;

                    if (current == '-') {
                        di = 0; dj = 1;
                    } else if (current == '|') {
                        di = 1; dj = 0;
                    } else if (current == '\\') {
                        di = 1; dj = 1;
                    } else if (current == '/') {
                        di = -1; dj = 1;
                    } else {
                        continue;
                    }

                    int ci = i, cj = j;
                    bool valid = true;

                    while (ci >= 0 && ci < N && cj >= 0 && cj < M && matrix[ci][cj] == current) {
                        if (visited[ci][cj]) {
                            valid = false;
                            break;
                        }

                        visited[ci][cj] = true;
                        ci += di;
                        cj += dj;
                    }

                    if (valid) {
                        line_count++;
                    } else {

                    }
                }
            }
        }

        if (line_count == 1) {
            cout << "CORRECT\n";
        } else {
            cout << "INCORRECT\n";
        }
    }
}