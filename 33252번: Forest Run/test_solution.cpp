#include <gtest/gtest.h>
#include <vector>

using namespace std;

long long compute_distance(int n, const vector<int> &entrances, const vector<vector<int>> &children)
{
    vector<char> visited(n + 1);
    long long ans = 0;
    vector<pair<int, int>> q;
    q.reserve(n);

    for (int r : entrances)
        q.emplace_back(r, 0);
    size_t head = 0;
    while (head < q.size())
    {
        auto [u, d] = q[head++];
        if (visited[u])
            continue;
        visited[u] = 1;
        const auto &ch = children[u];
        if (ch.empty())
            ans += 2LL * d;
        else
            for (int v : ch)
                if (!visited[v])
                    q.emplace_back(v, d + 1);
    }

    return ans;
}

TEST(ForestRun, Sample1)
{
    int n = 7;
    vector<int> entrances = {1};
    vector<vector<int>> ch(8);
    ch[1] = {2, 3};
    ch[2] = {4, 5};
    ch[3] = {6, 7};

    EXPECT_EQ(compute_distance(n, entrances, ch), 16);
}

TEST(ForestRun, Sample2)
{
    int n = 6;
    vector<int> entrances = {1, 5};
    vector<vector<int>> ch(7);
    ch[1] = {2};
    ch[2] = {3, 4};
    ch[5] = {6};
    EXPECT_EQ(compute_distance(n, entrances, ch), 10);
}

TEST(ForestRun, SingleNode)
{
    int n = 1;
    vector<int> entrances = {1};
    vector<vector<int>> ch(2);
    EXPECT_EQ(compute_distance(n, entrances, ch), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}