#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class University
{
public:
    string name;
    int sum;
    int count;
    University(string n, int s, int c) : name(n), sum(s), count(c) {}
    double average() const { return (double)sum / count; }
};

class OverallRanking
{
public:
    void run()
    {
        int n;
        cin >> n;

        unordered_map<string, pair<int, int>> uniMap;
        string uni;

        for (int i = 1; i <= n; i++)
        {
            cin >> uni;
            if (uniMap.find(uni) == uniMap.end())
            {
                uniMap[uni] = {i, 1};
            }
            else
            {
                uniMap[uni].first += i;
                uniMap[uni].second++;
            }
        }

        vector<University> vec;
        for (auto &p : uniMap)
        {
            vec.push_back(University(p.first, p.second.first, p.second.second));
        }

        sort(vec.begin(), vec.end(), [](const University &a, const University &b)
             { return a.average() < b.average(); });

        for (auto &u : vec)
        {
            cout << u.name << "\n";
        }
    }
};

int main()
{
    OverallRanking orank;
    orank.run();

    return 0;
}