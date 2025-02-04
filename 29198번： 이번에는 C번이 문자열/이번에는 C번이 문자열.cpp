#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

struct StringInfo
{
    string s;
    array<int, 26> freq;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<StringInfo> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].s;
        arr[i].freq.fill(0);
        for (char c : arr[i].s)
        {
            arr[i].freq[c - 'A']++;
        }
    }

    sort(arr.begin(), arr.end(), [](const StringInfo &a, const StringInfo &b)
         {
        for (int i = 0; i < 26; i++) {
            if (a.freq[i] != b.freq[i]) {
                return a.freq[i] > b.freq[i];
            }
        }

        return false; });

    array<int, 26> totalFreq;
    totalFreq.fill(0);

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            totalFreq[j] += arr[i].freq[j];
        }
    }

    string ans;
    for (int c = 0; c < 26; c++)
    {
        ans.append(totalFreq[c], 'A' + c);
    }

    cout << ans << "\n";
    return 0;
}