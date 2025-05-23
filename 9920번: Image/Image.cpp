#include <iostream>
#include <vector>

using namespace std;

int compress(const vector<vector<int>> &image, int r, int c, int n)
{
    int first = image[r][c];
    bool same = true;

    for (int i = r; i < r + n && same; i++)
    {
        for (int j = c; j < c + n; j++)
        {
            if (image[i][j] != first)
            {
                same = false;
                break;
            }
        }
    }

    if (same)
        return 2;
    int half = n / 2;
    int sum = 1;

    sum += compress(image, r, c, half);
    sum += compress(image, r, c + half, half);
    sum += compress(image, r + half, c, half);
    sum += compress(image, r + half, c + half, half);

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;

    vector<vector<int>> image(L, vector<int>(L));
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            cin >> image[i][j];
        }
    }

    cout << compress(image, 0, 0, L);
    return 0;
}