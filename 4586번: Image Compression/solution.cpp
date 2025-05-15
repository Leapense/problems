#include <bits/stdc++.h>
using namespace std;

struct PrefixSum2D
{
    vector<vector<int>> sum;
    PrefixSum2D(const vector<string>& image, char color)
    {
        int n = image.size();
        sum.assign(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (image[i - 1][j - 1] == color ? 1 : 0);
            }
        }
    }

    int count(int r1, int c1, int r2, int c2) const {
        return sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
    }
};

void compress(vector<string>& out, int x, int y, int sz, const PrefixSum2D& sum0, const PrefixSum2D& sum1, int T, char fill = ' ') {
    int total = sz * sz;
    int cnt0 = sum0.count(x, y, x + sz, y + sz);
    int cnt1 = sum1.count(x, y, x + sz, y + sz);

    if (cnt0 * 100 >= T * total) {
        for (int i = x; i < x + sz; ++i)
        {
            for (int j = y; j < y + sz; ++j)
            {
                out[i][j] = '0';
            }
        }

        return;
    }

    if (cnt1 * 100 >= T * total) {
        for (int i = x; i < x + sz; ++i)
        {
            for (int j = y; j < y + sz; ++j)
            {
                out[i][j] = '1';
            }
        }

        return;
    }

    int half = sz / 2;
    compress(out, x, y + half, half, sum0, sum1, T);
    compress(out, x, y, half, sum0, sum1, T);
    compress(out, x + half, y, half, sum0, sum1, T);
    compress(out, x + half, y + half, half, sum0, sum1, T);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int image_num = 1;
    while (true)
    {
        int W, T;
        cin >> W;

        if (W == 0) break;
        cin >> T;
        vector<string> image(W);
        for (int i = 0; i < W; ++i)
        {
            cin >> image[i];
        }

        PrefixSum2D sum0(image, '0'), sum1(image, '1');
        vector<string> output = image;
        compress(output, 0, 0, W, sum0, sum1, T);

        cout << "Image " << image_num++ << ":\n";
        for (const auto& row : output)
        {
            cout << row << "\n";
        }
    }

    return 0;
}