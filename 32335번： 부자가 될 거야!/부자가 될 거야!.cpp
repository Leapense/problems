#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    for (int i = 0; i < N; i++)
    {
        int digit = S[i] - '0';
        if (digit != 0)
        {
            int cost = 10 - digit;
            if (M >= cost)
            {
                S[i] = '0';
                M -= cost;
            }
        }
    }

    int r = M % 10;
    int lastDigit = S[N - 1] - '0';
    int newDigit = (lastDigit + r) % 10;
    S[N - 1] = char(newDigit + '0');

    cout << S;
    return 0;
}