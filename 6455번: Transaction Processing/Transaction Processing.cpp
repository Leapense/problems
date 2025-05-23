#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Entry
{
    string seq;
    string acct;
    int amount;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, string> acctMap;
    string acctNum, acctName;
    while (true)
    {
        getline(cin, acctNum);
        if (acctNum.substr(0, 3) == "000")
            break;
        string num = acctNum.substr(0, 3);
        string name = acctNum.substr(3);
        while (!name.empty() && name[0] == ' ')
            name.erase(name.begin());
        acctMap[num] = name;
    }
    vector<Entry> trans;
    string line;
    while (getline(cin, line))
    {
        if (line.substr(0, 3) == "000")
            break;
        Entry e;
        e.seq = line.substr(0, 3);
        e.acct = line.substr(3, 3);
        string amtStr = line.substr(6);
        while (!amtStr.empty() && amtStr[0] == ' ')
            amtStr.erase(amtStr.begin());
        e.amount = stoi(amtStr);
        trans.push_back(e);
    }
    int i = 0;
    while (i < trans.size())
    {
        string currentSeq = trans[i].seq;
        vector<Entry> entries;
        int sum = 0;
        while (i < trans.size() && trans[i].seq == currentSeq)
        {
            entries.push_back(trans[i]);
            sum += trans[i].amount;
            i++;
        }
        if (sum != 0)
        {
            cout << "*** Transaction " << currentSeq << " is out of balance ***\n";
            for (auto &e : entries)
            {
                cout << e.acct << " ";
                cout << left << setw(30) << acctMap[e.acct] << " ";
                cout << right << setw(10) << fixed << setprecision(2) << e.amount / 100.0 << "\n";
            }
            cout << "999 " << left << setw(30) << "Out of Balance" << " ";
            cout << right << setw(10) << fixed << setprecision(2) << -sum / 100.0 << "\n\n";
        }
    }
    return 0;
}