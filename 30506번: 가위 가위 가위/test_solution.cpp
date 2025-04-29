#include "solution.cpp"
#include <gtest/gtest.h>
#include <random>

static vector<int> simulateResponses(const string &machine, int K0)
{
    int N = machine.size();
    vector<int> W(N);
    for (int i = 0; i < N; ++i)
    {
        int delta = (machine[i] == '5' ? -1 : machine[i] == '2' ? +1
                                                                : 0);
        W[i] = K0 + delta;
    }
    return W;
}

TEST(RPSSolverTest, AllRock)
{
    string machine(100, '0');
    int K0 = 0; // scissors vs rock yields no wins
    auto W = simulateResponses(machine, K0);
    EXPECT_EQ(deduceMachine(K0, W), machine);
}

TEST(RPSSolverTest, AllScissors)
{
    string machine(100, '2');
    int K0 = 0; // scissors vs scissors ⇒ all ties
    auto W = simulateResponses(machine, K0);
    EXPECT_EQ(deduceMachine(K0, W), machine);
}

TEST(RPSSolverTest, AllPaper)
{
    string machine(100, '5');
    int K0 = 100; // scissors beats paper in all 100 positions
    auto W = simulateResponses(machine, K0);
    EXPECT_EQ(deduceMachine(K0, W), machine);
}

TEST(RPSSolverTest, RandomMachine)
{
    static std::mt19937_64 rng(12345);
    static std::vector<char> moves = {'0', '2', '5'};
    string machine(100, '0');
    for (int i = 0; i < 100; ++i)
        machine[i] = moves[rng() % 3];
    int K0 = int(count(machine.begin(), machine.end(), '5'));
    auto W = simulateResponses(machine, K0);
    EXPECT_EQ(deduceMachine(K0, W), machine);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}