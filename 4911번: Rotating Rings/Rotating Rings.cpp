#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1000;

vector<int> extractRing(const vector<vector<int>> &matrix, int ringIndex)
{
    int n = matrix.size();
    vector<int> ringElements;

    int start = ringIndex;
    int end = n - ringIndex - 1;

    if (start == end)
    {
        ringElements.push_back(matrix[start][start]);
        return ringElements;
    }

    for (int col = start; col <= end; col++)
    {
        ringElements.push_back(matrix[start][col]);
    }

    for (int row = start + 1; row <= end - 1; row++)
    {
        ringElements.push_back(matrix[row][end]);
    }

    for (int col = end; col >= start; col--)
    {
        ringElements.push_back(matrix[end][col]);
    }

    for (int row = end - 1; row >= start + 1; row--)
    {
        ringElements.push_back(matrix[row][start]);
    }

    return ringElements;
}

bool canRotateMatch(const vector<int> &ringA, const vector<int> &ringB)
{
    if (ringA.size() != ringB.size())
    {
        return false;
    }

    if (ringA.size() <= 1)
    {
        return ringA == ringB;
    }

    vector<int> dbl;
    dbl.reserve(ringB.size() * 2);
    dbl.insert(dbl.end(), ringB.begin(), ringB.end());
    dbl.insert(dbl.end(), ringB.begin(), ringB.end());

    for (int start = 0; start < (int)ringB.size(); start++)
    {
        bool match = true;
        for (int k = 0; k < (int)ringA.size(); k++)
        {
            if (ringA[k] != dbl[start + k])
            {
                match = false;
                break;
            }
        }

        if (match)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, testCase = 0;

    while (true)
    {
        cin >> N;
        if (!cin || N == 0)
        {
            break;
        }

        testCase++;

        vector<vector<int>> matrix(N, vector<int>(N));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }

        vector<vector<int>> sortedMatrix(N, vector<int>(N));

        int val = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                sortedMatrix[i][j] = val++;
            }
        }

        int ringsCount = (N + 1) / 2;
        bool canBeSorted = true;

        for (int ringIndex = 0; ringIndex < ringsCount; ringIndex++)
        {
            vector<int> ringA = extractRing(matrix, ringIndex);
            vector<int> ringB = extractRing(sortedMatrix, ringIndex);

            if (!canRotateMatch(ringA, ringB))
            {
                canBeSorted = false;
                break;
            }
        }

        cout << testCase << ". " << (canBeSorted ? "YES" : "NO") << "\n";
    }

    return 0;
}