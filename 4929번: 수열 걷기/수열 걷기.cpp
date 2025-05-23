#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int n;
        cin >> n;
        if (!cin || n == 0)
            break;
        vector<long long> seq1(n);
        for (int i = 0; i < n; i++)
            cin >> seq1[i];
        int m;
        cin >> m;
        vector<long long> seq2(m);
        for (int j = 0; j < m; j++)
            cin >> seq2[j];
        long long sum1 = 0, sum2 = 0, result = 0;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (seq1[i] < seq2[j])
            {
                sum1 += seq1[i++];
            }
            else if (seq1[i] > seq2[j])
            {
                sum2 += seq2[j++];
            }
            else
            {
                result += max(sum1, sum2) + seq1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < n)
        {
            sum1 += seq1[i++];
        }
        while (j < m)
        {
            sum2 += seq2[j++];
        }
        result += max(sum1, sum2);
        cout << result << "\n";
    }
    return 0;
}
