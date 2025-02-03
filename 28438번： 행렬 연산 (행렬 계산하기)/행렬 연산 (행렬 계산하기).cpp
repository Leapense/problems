#include <iostream>
#include <vector>
using namespace std;

class MatrixOperator
{
public:
    int N, M, Q;
    vector<long long> row, col;

    MatrixOperator(int n, int m, int q) : N(n), M(m), Q(q)
    {
        row.assign(n, 0);
        col.assign(m, 0);
    }

    void processOperation(int type, int index, int value)
    {
        if (type == 1)
        {
            row[index - 1] += value;
        }
        else
        {
            col[index - 1] += value;
        }
    }

    void printResult()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << row[i] + col[j] << (j == M - 1 ? "\n" : " ");
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    MatrixOperator solver(N, M, Q);
    int type, index, value;

    for (int i = 0; i < Q; i++)
    {
        cin >> type >> index >> value;
        solver.processOperation(type, index, value);
    }

    solver.printResult();

    return 0;
}