#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();

struct Best
{
    ll cost;
    int route;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, N;
    cin >> A >> B >> N;
    ll ans = INF;
    const int MAXCITY = 10000;
    vector<Best> bestA(MAXCITY + 1, {INF, -1});
    vector<Best> bestB(MAXCITY + 1, {INF, -1});
    for (int i = 0; i < N; i++)
    {
        int cost, num;
        cin >> cost >> num;
        vector<int> cities(num);
        for (int j = 0; j < num; j++)
        {
            cin >> cities[j];
        }
        int posA = -1, posB = -1;
        for (int j = 0; j < num; j++)
        {
            if (cities[j] == A)
                posA = j;
            if (cities[j] == B)
                posB = j;
        }
        if (posA != -1 && posB != -1 && posA < posB)
        {
            ans = min(ans, (ll)cost);
        }
        if (posA != -1)
        {
            for (int j = posA + 1; j < num; j++)
            {
                int city = cities[j];
                if (cost < bestA[city].cost)
                {
                    bestA[city] = {cost, i};
                }
            }
        }
        if (posB != -1)
        {
            for (int j = 0; j < posB; j++)
            {
                int city = cities[j];
                if (cost < bestB[city].cost)
                {
                    bestB[city] = {cost, i};
                }
            }
        }
    }
    for (int city = 1; city <= MAXCITY; city++)
    {
        if (bestA[city].cost != INF && bestB[city].cost != INF)
        {
            if (bestA[city].route != bestB[city].route)
            {
                ans = min(ans, bestA[city].cost + bestB[city].cost);
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}