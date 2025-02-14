#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    int *A = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    bool possible = true;

    for (int i = 1; i <= N; i++)
    {
        if ((i % k) != ((A[i] + 1) % k))
        {
            possible = false;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";

    delete[] A;
    return 0;
}