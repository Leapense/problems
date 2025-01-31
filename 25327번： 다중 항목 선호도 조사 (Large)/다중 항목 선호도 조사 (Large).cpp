#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class PreferenceQuery
{
private:
    unordered_map<string, int> preferenceMap;
    int n, m;

    string createKey(const string &subject, const string &fruit, const string &color)
    {
        return subject + " " + fruit + " " + color;
    }

public:
    PreferenceQuery(int n, int m) : n(n), m(m) {}

    void addPreference(const string &subject, const string &fruit, const string &color)
    {
        string key = createKey(subject, fruit, color);
        preferenceMap[key]++;
    }

    int query(const string &subject, const string &fruit, const string &color)
    {
        int count = 0;
        for (const auto &entry : preferenceMap)
        {
            stringstream ss(entry.first);
            string s, f, c;
            ss >> s >> f >> c;

            if ((subject == "-" || subject == s) &&
                (fruit == "-" || fruit == f) &&
                (color == "-" || color == c))
            {
                count += entry.second;
            }
        }
        return count;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    PreferenceQuery pq(n, m);

    for (int i = 0; i < n; ++i)
    {
        string subject, fruit, color;
        cin >> subject >> fruit >> color;
        pq.addPreference(subject, fruit, color);
    }

    for (int i = 0; i < m; ++i)
    {
        string subject, fruit, color;
        cin >> subject >> fruit >> color;
        cout << pq.query(subject, fruit, color) << '\n';
    }

    return 0;
}