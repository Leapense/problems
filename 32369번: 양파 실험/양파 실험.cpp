#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int praise = 1;
    int criticism = 1;

    for (int day = 1; day <= N; day++) {
        praise += A;
        criticism += B;

        if (criticism > praise) {
            swap(praise, criticism);
        }

        if (praise == criticism) {
            criticism -= 1;
        }
    }

    cout << praise << " " << criticism;

    return 0;
}