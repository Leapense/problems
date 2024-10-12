#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> find_and_order_enemies(int n, vector<int>& f)
{

    int total_sum = accumulate(f.begin(), f.end(), 0);

    for (int i = 0; i < n; ++i)
    {

        if (f[i] == total_sum - f[i])
        {

            int boss = f[i];

            vector<int> result;

            for (int j = 0; j < n; ++j)
            {

                if (i != j)
                {

                    result.push_back(f[j]);

                }

            }

            result.push_back(boss);

            return result;

        }

    }

    return {};

}

int main()
{

    int n;

    cin >> n;

    vector<int> f(n);

    for (int i = 0; i < n; ++i)
    {

        cin >> f[i];

    }

    vector<int> ordered_enemies = find_and_order_enemies(n, f);

    for (int i = 0; i < ordered_enemies.size(); ++i)
    {

        cout << ordered_enemies[i] << " ";

    }

    cout << endl;

    return 0;

}