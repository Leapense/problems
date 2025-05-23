#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Read the complete matrix.
    // We only need the first row to determine the groups.
    vector<vector<char>> matrix(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Using node 0 as the reference, assign each node to a group.
    // We assign group[0] arbitrarily to true.
    // For any other node i, if the relationship with node 0 is '+', assign the same group; otherwise, the opposite group.
    vector<bool> group(n, false);
    group[0] = true;
    for (int i = 1; i < n; i++)
    {
        group[i] = (matrix[0][i] == '+');
    }

    // Process the queries.
    int m;
    cin >> m;
    while (m--)
    {
        int b, c;
        cin >> b >> c;
        // Nodes in the same group have a '+' relationship, otherwise '-'
        cout << (group[b] == group[c] ? "+" : "-") << "\n";
    }

    return 0;
}
