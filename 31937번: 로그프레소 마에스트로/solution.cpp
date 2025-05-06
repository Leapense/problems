#include <iostream>
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> infected(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> infected[i];
    }

    std::vector<LogEntry> logs(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> logs[i].time >> logs[i].from >> logs[i].to;
    }

    int result = findPatientZero(n, logs, infected);
    std::cout << result << std::endl;

    return 0;
}