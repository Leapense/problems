#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> grid(N);

    for(int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    string target = "MOBIS";
    int target_length = target.length();
    int count = 0;

    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'M') {
                for (int dir = 0; dir < 8; dir++) {
                    int ni = i, nj = j;
                    bool match = true;

                    for (int k = 0; k < target_length; k++) {
                        if (ni < 0 or ni >= N or nj < 0 or nj >= N) {
                            match = false;
                            break;
                        }

                        if (grid[ni][nj] != target[k]) {
                            match = false;
                            break;
                        }

                        ni += dx[dir];
                        nj += dy[dir];
                    }

                    if (match) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}