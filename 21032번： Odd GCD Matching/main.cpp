#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num % 2 == 0)
        {
            ++evenCount;
        }
        else
        {
            ++oddCount;
        }
    }

    int answer = 0;
    if (oddCount < evenCount)
    {
        answer = oddCount;
    }
    else
    {
        answer = evenCount + (oddCount - evenCount) / 2;
    }

    cout << answer << "\n";
    return 0;
}