#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> image(H);
    for (int i = 0; i < H; i++)
    {
        cin >> image[i];
    }

    int P;
    cin >> P;
    vector<vector<string>> stamps(P);
    vector<int> stampH(P), stampW(P);
    for (int p = 0; p < P; p++)
    {
        cin >> stampH[p] >> stampW[p];
        stamps[p].resize(stampH[p]);
        for (int i = 0; i < stampH[p]; i++)
        {
            cin >> stamps[p][i];
        }
    }

    vector<vector<bool>> cover(H, vector<bool>(W, false));

    // Process each stamp
    for (int p = 0; p < P; p++)
    {
        int min_r = stampH[p], min_c = stampW[p];
        int max_r = -1, max_c = -1;
        // Find bounding box of '#' in the stamp
        for (int i = 0; i < stampH[p]; i++)
        {
            for (int j = 0; j < stampW[p]; j++)
            {
                if (stamps[p][i][j] == '#')
                {
                    min_r = min(min_r, i);
                    min_c = min(min_c, j);
                    max_r = max(max_r, i);
                    max_c = max(max_c, j);
                }
            }
        }
        // If no '#' exists in stamp, skip it.
        if (max_r == -1)
            continue;
        int h = max_r - min_r + 1;
        int w = max_c - min_c + 1;
        // Collect relative positions of '#' in the bounding box
        vector<pair<int, int>> rel;
        for (int i = min_r; i <= max_r; i++)
        {
            for (int j = min_c; j <= max_c; j++)
            {
                if (stamps[p][i][j] == '#')
                {
                    rel.push_back({i - min_r, j - min_c});
                }
            }
        }
        // Try all placements of the bounding box inside the image
        for (int i = 0; i <= H - h; i++)
        {
            for (int j = 0; j <= W - w; j++)
            {
                bool valid = true;
                for (auto &d : rel)
                {
                    int ni = i + d.first, nj = j + d.second;
                    if (image[ni][nj] != '#')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    for (auto &d : rel)
                    {
                        cover[i + d.first][j + d.second] = true;
                    }
                }
            }
        }
    }

    bool possible = true;
    for (int i = 0; i < H && possible; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (image[i][j] == '#' && !cover[i][j])
            {
                possible = false;
                break;
            }
        }
    }
    cout << (possible ? "TAK" : "NIE") << "\n";

    return 0;
}
