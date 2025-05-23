#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long low = 1;
    long long high = N;
    int query_count = 0;

    const int MAX_QUERIES = 50;

    while (low <= high && query_count < MAX_QUERIES) {
        long long mid = low + (high - low) / 2;

        cout << "? " << mid << "\n";
        cout.flush();
        query_count++;

        int response;
        cin >> response;

        if (response == 0) {
            cout << "= " << mid << "\n";
            cout.flush();
            return 0;
        }
        else if (response == -1) {
            low = mid + 1;
        }
        else if (response == 1) {
            high = mid - 1;
        }
        else {
            cerr << "Unexpected response: " << response << "\n";
            return 1;
        }
    }

    cout << "= " << low << "\n";
    cout.flush();

    return 0;
}