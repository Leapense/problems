#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int r, c1, c2;
    cin >> r >> c1 >> c2;
    vector<string> leftScan(r), rightScan(r);
    for (int i = 0; i < r; i++)
        cin >> leftScan[i];
    for (int i = 0; i < r; i++)
        cin >> rightScan[i];
    bool mesh = false;
    int m = min(c1, c2);
    for (int k = 1; k <= m; k++)
    {
        bool valid = true;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c1 - k; j++)
            {
                if (leftScan[i][j] != '1')
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
            for (int j = 0; j < k; j++)
            {
                if (leftScan[i][c1 - k + j] == rightScan[i][j])
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
            for (int j = k; j < c2; j++)
            {
                if (rightScan[i][j] != '1')
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }
        if (valid)
        {
            mesh = true;
            break;
        }
    }
    cout << (mesh ? "Yes" : "No") << "\n";
    return 0;
}
