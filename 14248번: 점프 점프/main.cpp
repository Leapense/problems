#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> jump(n);

    for (int i = 0; i < n; i++)
    {
        cin >> jump[i];
    }

    int s;
    cin >> s;

    s--;

    vector<bool> visited(n, false);

    queue<int> q;

    visited[s] = true;
    q.push(s);
    int count = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int left = cur - jump[cur];
        int right = cur + jump[cur];

        if (left >= 0 && !visited[left])
        {
            visited[left] = true;
            q.push(left);
            count++;
        }

        if (right < n && !visited[right])
        {
            visited[right] = true;
            q.push(right);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}