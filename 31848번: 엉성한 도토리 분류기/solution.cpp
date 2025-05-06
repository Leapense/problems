#include <bits/stdc++.h>
using namespace std;

vector<int> ClassifyAcorns(const vector<int> &holeSizes, const vector<int> &acronSizes)
{
    const int N = static_cast<int>(holeSizes.size());
    vector<int> prefixMax(N);

    for (int i = 0; i < N; ++i)
    {
        int T = holeSizes[i] + i;
        prefixMax[i] = (i == 0) ? T : max(prefixMax[i - 1], T);
    }

    vector<int> result;
    result.reserve(acronSizes.size());

    for (int s : acronSizes)
    {
        auto it = lower_bound(prefixMax.begin(), prefixMax.end(), s);
        result.push_back(static_cast<int>(it - prefixMax.begin()) + 1);
    }

    return result;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<int> holes(N);
    for (int &x : holes)
        cin >> x;

    int Q;
    cin >> Q;
    vector<int> acorns(Q);
    for (int &x : acorns)
        cin >> x;

    auto ans = ClassifyAcorns(holes, acorns);

    for (size_t i = 0; i < ans.size(); ++i)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }

    cout << "\n";
    return 0;
}
#endif