#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<int> arr(N);
    unordered_map<int, int> freq;
    unordered_map<int, int> firstOccurrence;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        if (!firstOccurrence.count(arr[i]))
        {
            firstOccurrence[arr[i]] = i;
        }
    }

    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        if (freq[a] == freq[b]) {
            return firstOccurrence[a] < firstOccurrence[b];
        }
        return freq[a] > freq[b]; });

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}