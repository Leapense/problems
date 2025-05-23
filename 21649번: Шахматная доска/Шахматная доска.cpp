#include <bits/stdc++.h>
using namespace std;

long long m, n, i, j, c, totalCells, blackCells, whiteCells;
bool cellColor;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    cin >> m >> n >> i >> j >> c;
    totalCells = m * n;
    
    if (totalCells % 2 == 0) {
        blackCells = whiteCells = totalCells / 2;
    } else {
        blackCells = totalCells / 2 + 1;
        whiteCells = totalCells / 2;
    }


    cellColor = ((i + j) % 2 == 0) ? 0 : 1;

    if (c != cellColor) {
        swap(blackCells, whiteCells);
    }

    if (blackCells > whiteCells) {
        cout << "black\n";
    } else if (whiteCells > blackCells) {
        cout << "white\n";
    } else {
        cout << "equal\n";
    }

    return 0;
}