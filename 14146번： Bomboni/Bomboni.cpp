#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    vector<int> divCount(B + 1, 0);

    for (int i = 1; i <= B; i++)
    {
        for (int j = i; j <= B; j += i)
        {
            divCount[j]++;
        }
    }

    int maxDiv = 0;
    for (int i = A; i <= B; i++)
    {
        if (divCount[i] > maxDiv)
        {
            maxDiv = divCount[i];
        }
    }

    vector<int> answers;
    for (int i = A; i <= B; i++)
    {
        if (divCount[i] == maxDiv)
        {
            answers.push_back(i);
        }
    }

    cout << maxDiv << " " << answers.size() << "\n";
    for (int x : answers)
    {
        cout << x << "\n";
    }

    return 0;
}