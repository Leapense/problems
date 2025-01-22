#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        bool impossible = false;
        if (C > A || C > B || (A + B - C) > N || (A == C && B == C && N != C))
        {
            impossible = true;
        }
        if (impossible)
        {
            printf("Case #%d: IMPOSSIBLE\n", tc);
            continue;
        }

        int left_visible = A - C;
        int right_visible = B - C;
        int remaining = N - (A + B - C);

        vector<int> left_heights;

        for (int i = 1; i <= left_visible; i++)
            left_heights.push_back(i + 1);

        vector<int> middle_heights(C, N);
        vector<int> right_heights;

        for (int i = 1; i <= right_visible; i++)
            right_heights.push_back(i + 1 + left_visible);

        sort(right_heights.begin(), right_heights.end(), greater<int>());

        vector<int> remaining_heights(remaining, 1);
        vector<int> sequence;

        if (left_visible > 0)
        {
            sequence.insert(sequence.end(), left_heights.begin(), left_heights.end());
            sequence.insert(sequence.end(), remaining_heights.begin(), remaining_heights.end());
        }
        else
        {
            sequence.insert(sequence.end(), middle_heights.begin(), middle_heights.end());
            sequence.insert(sequence.end(), remaining_heights.begin(), remaining_heights.end());
        }

        if (left_visible > 0)
        {
            sequence.insert(sequence.end(), middle_heights.begin(), middle_heights.end());
        }
        else
        {
        }

        sequence.insert(sequence.end(), right_heights.begin(), right_heights.end());

        if (left_visible > 0)
        {
        }
        if (left_visible == 0)
        {
        }
        printf("Case #%d:", tc);
        for (auto num : sequence)
            printf(" %d", num);
        printf("\n");
    }

    return 0;
}