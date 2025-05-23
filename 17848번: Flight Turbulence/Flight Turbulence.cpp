#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[m] == m) {
        cout << 0;
        return 0;
    }

    int count = 0;
    int current = m;

    vector<bool> visited(n + 1, false);

    while(true) {
        visited[current] = true;
        count++;
        current = a[current];

        if (current == m) {
            break;
        }
    }

    cout << count << endl;

    return 0;
}