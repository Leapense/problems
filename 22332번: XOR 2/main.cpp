//=====================================================================
//   22332번:    XOR 2                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/22332  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> image;
vector<vector<bool>> covered;
vector<vector<int>> operations;

int main() {
    cin >> N;
    image.resize(N, vector<int>(N));
    covered.resize(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> image[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (image[i][j] == 1 && !covered[i][j]) {
                int w1 = 1;
                while (j + w1 < N && image[i][j + w1] == 1 && !covered[i][j + w1])
                    ++w1;
                int h1 = 1;
                bool can_extend_h1 = true;
                while (can_extend_h1) {
                    if (i + h1 >= N)
                        break;
                    for (int k = 0; k < w1; ++k) {
                        if (image[i + h1][j + k] != 1 || covered[i + h1][j + k]) {
                            can_extend_h1 = false;
                            break;
                        }
                    }
                    if (can_extend_h1)
                        ++h1;
                }
                int area1 = w1 * h1;

                int h2 = 1;
                while (i + h2 < N && image[i + h2][j] == 1 && !covered[i + h2][j])
                    ++h2;
                int w2 = 1;
                bool can_extend_w2 = true;
                while (can_extend_w2) {
                    if (j + w2 >= N)
                        break;
                    for (int k = 0; k < h2; ++k) {
                        if (image[i + k][j + w2] != 1 || covered[i + k][j + w2]) {
                            can_extend_w2 = false;
                            break;
                        }
                    }
                    if (can_extend_w2)
                        ++w2;
                }
                int area2 = w2 * h2;

                int w, h;
                if (area1 >= area2) {
                    w = w1;
                    h = h1;
                } else {
                    w = w2;
                    h = h2;
                }

                for (int a = 0; a < h; ++a)
                    for (int b = 0; b < w; ++b)
                        covered[i + a][j + b] = true;
                operations.push_back({j + 1, j + w, i + 1, i + h});
            }
        }
    }

    cout << operations.size() << endl;
    for (auto &op : operations)
        cout << op[0] << " " << op[1] << " " << op[2] << " " << op[3] << endl;

    return 0;
}

