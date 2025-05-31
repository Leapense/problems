#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    // 1) A, B 행렬 선언 및 입력
    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> D(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[i][j] = B[i][j] - A[i][j];
        }
    }

    int base = D[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] - D[i][0] != D[0][j] - base) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    int LB = -100000000;
    int UB = 100000000;

    for (int i = 0; i < m; i++)
    {
        int low_i = -D[i][0];
        int high_i = 9 - D[i][0];
        LB = max(LB, low_i);
        UB = min(UB, high_i);
    }

    for (int j = 0; j < n; j++)
    {
        int low_j = D[0][j] - base;
        int high_j = 9 + D[0][j] - base;
        LB = max(LB, low_j);
        UB = min(UB, high_j);
    }

    if (LB > UB) {
        cout << "-1\n";
        return 0;
    }

    int w = LB;
    for (int i = 0; i < m; i++) {
        int ri = D[i][0] + w;
        cout << ri;
    }

    cout << "\n";
    return 0;
}