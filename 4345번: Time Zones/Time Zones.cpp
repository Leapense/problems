#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int T;
    cin >> T;
    map<string, double> offset = {
        {"UTC", 0}, {"GMT", 0}, {"BST", 1}, {"IST", 1}, {"WET", 0}, {"WEST", 1}, {"CET", 1}, {"CEST", 2}, {"EET", 2}, {"EEST", 3}, {"MSK", 3}, {"MSD", 4}, {"AST", -4}, {"ADT", -3}, {"NST", -3.5}, {"NDT", -2.5}, {"EST", -5}, {"EDT", -4}, {"CST", -6}, {"CDT", -5}, {"MST", -7}, {"MDT", -6}, {"PST", -8}, {"PDT", -7}, {"HST", -10}, {"AKST", -9}, {"AKDT", -8}, {"AEST", 10}, {"AEDT", 11}, {"ACST", 9.5}, {"ACDT", 10.5}, {"AWST", 8}};
    string dummy;
    getline(cin, dummy);
    for (int i = 0; i < T; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string token;
        iss >> token;
        int minutes = 0;
        string tz1, tz2;
        if (token == "noon")
        {
            minutes = 12 * 60;
            iss >> tz1 >> tz2;
        }
        else if (token == "midnight")
        {
            minutes = 0;
            iss >> tz1 >> tz2;
        }
        else
        {
            string timeStr = token;
            string period;
            iss >> period;
            iss >> tz1 >> tz2;
            int colon = timeStr.find(":");
            int hour = stoi(timeStr.substr(0, colon));
            int min = stoi(timeStr.substr(colon + 1));
            if (period == "a.m.")
            {
                if (hour == 12)
                    hour = 0;
            }
            else
            {
                if (hour != 12)
                    hour += 12;
            }
            minutes = hour * 60 + min;
        }
        double off1 = offset[tz1] * 60;
        double off2 = offset[tz2] * 60;
        int utc = minutes - (int)off1;
        int target = utc + (int)off2;
        target = (target % 1440 + 1440) % 1440;
        if (target == 0)
        {
            cout << "midnight" << "\n";
        }
        else if (target == 720)
        {
            cout << "noon" << "\n";
        }
        else
        {
            int h = target / 60;
            int m = target % 60;
            string period;
            if (h == 0)
            {
                h = 12;
                period = "a.m.";
            }
            else if (h < 12)
            {
                period = "a.m.";
            }
            else if (h == 12)
            {
                period = "p.m.";
            }
            else
            {
                h -= 12;
                period = "p.m.";
            }
            cout << h << ":" << setw(2) << setfill('0') << m << " " << period << "\n";
        }
    }
    return 0;
}
