#include <iostream>
#include <vector>

struct Bug
{
    int birthYear;
    int divisions;
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<Bug> bugs;
    bugs.push_back({1, 0});

    for (int year = 2; year <= N; ++year)
    {
        int size = bugs.size();

        std::vector<Bug> newBugs;
        for (int i = 0; i < size; i++)
        {
            bugs[i].divisions++;
            newBugs.push_back({year, 0});
        }

        bugs.insert(bugs.end(), newBugs.begin(), newBugs.end());

        std::vector<Bug> alive;

        for (auto &bug : bugs)
        {
            if ((bug.birthYear % 2 == 1 && bug.divisions == 3) || (bug.birthYear % 2 == 0 && bug.divisions == 4))
            {
                continue;
            }
            alive.push_back(bug);
        }
        bugs = alive;
    }

    std::cout << bugs.size() << "\n";

    return 0;
}