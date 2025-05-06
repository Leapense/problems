#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct LogEntry
{
    long long time;
    int from;
    int to;
};

bool canExplainAllInfections(const std::vector<LogEntry> &logs, const std::vector<int> &infected, int n, int startComputer)
{
    std::unordered_set<int> currentlyInfected;
    currentlyInfected.insert(startComputer);

    for (const auto &log : logs)
    {
        if (currentlyInfected.count(log.from) > 0)
        {
            currentlyInfected.insert(log.to);
        }
    }

    for (int computer : infected)
    {
        if (currentlyInfected.count(computer) == 0)
        {
            return false;
        }
    }

    std::unordered_set<int> infectedSet(infected.begin(), infected.end());

    for (int i = 1; i <= n; i++)
    {
        if (infectedSet.count(i) == 0 && currentlyInfected.count(i) > 0)
        {
            return false;
        }
    }

    return true;
}

int findPatientZero(int n, const std::vector<LogEntry> &logs, const std::vector<int> &infected)
{
    std::vector<LogEntry> sortedLogs = logs;
    std::sort(sortedLogs.begin(), sortedLogs.end(), [](const LogEntry &a, const LogEntry &b)
              { return a.time < b.time; });

    for (int candidate : infected)
    {
        if (canExplainAllInfections(sortedLogs, infected, n, candidate))
        {
            return candidate;
        }
    }

    return -1;
}

TEST(VirusTest, SampleTest)
{
    int n = 5, m = 4, k = 3;
    std::vector<int> infected = {3, 4, 5};
    std::vector<LogEntry> logs = {
        {4, 4, 5},
        {3, 3, 4},
        {2, 2, 3},
        {1, 1, 2}};

    EXPECT_EQ(findPatientZero(n, logs, infected), 3);
}

TEST(VirusTest, LinearInfection)
{
    int n = 5, m = 4, k = 5;
    std::vector<int> infected = {1, 2, 3, 4, 5};
    std::vector<LogEntry> logs = {
        {1, 1, 2},
        {2, 2, 3},
        {3, 3, 4},
        {4, 4, 5}};

    EXPECT_EQ(findPatientZero(n, logs, infected), 1);
}

TEST(VirusTest, StarInfection)
{
    int n = 5, m = 4, k = 5;
    std::vector<int> infected = {1, 2, 3, 4, 5};
    std::vector<LogEntry> logs = {
        {1, 1, 2},
        {2, 1, 3},
        {3, 1, 4},
        {4, 1, 5}};

    EXPECT_EQ(findPatientZero(n, logs, infected), 1);
}

TEST(VirusTest, ComplexInfection)
{
    int n = 7, m = 6, k = 4;
    std::vector<int> infected = {2, 4, 5, 7};
    std::vector<LogEntry> logs = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6},
        {5, 6, 7},
        {6, 3, 1}};

    EXPECT_EQ(findPatientZero(n, logs, infected), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}