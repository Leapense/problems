#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    queue<long long> que;
    unordered_map<long long, long long> freq;
    freq.reserve(n * 2);

    long long sum = 0;
    long long countModels = 0;

    while (n--)
    {
        char op;
        cin >> op;

        if (op == '+')
        {
            long long k;
            cin >> k;
            que.push(k);

            sum += k;
            countModels++;
            freq[k]++;
        }
        else if (op == '-')
        {
            long long x = que.front();
            que.pop();

            sum -= x;
            countModels--;
            freq[x]--;
        }
        else if (op == '?')
        {
            if (sum % countModels != 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                long long avg = sum / countModels;
                cout << (freq.count(avg) ? freq[avg] : 0) << endl;
            }
        }
    }

    return 0;
}