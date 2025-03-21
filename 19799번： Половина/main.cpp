#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int start = 2 * n;

    set<int> current;
    current.insert(start);

    for (int i = 0; i < k; i++)
    {
        set<int> next;
        for (int state : current)
        {
            if (state % 2 == 0)
            {
                if (state - 1 >= 0)
                {
                    next.insert(state - 1);
                }
                next.insert(state / 2);
            }
            else
            {
                if (state - 1 >= 0)
                {
                    next.insert(state - 1);
                }
            }
        }

        current = move(next);
    }

    vector<double> answers;

    for (int state : current)
    {
        answers.push_back(state / 2.0);
    }

    sort(answers.begin(), answers.end());

    cout << answers.size() << "\n";
    cout << fixed << setprecision(1);
    for (double apple : answers)
    {
        cout << apple << " ";
    }

    cout << "\n";
    return 0;
}