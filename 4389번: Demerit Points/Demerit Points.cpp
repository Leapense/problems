#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

struct Record {
    int demerit_points;
    int merit_points;
};

struct tm parseDate(const string& date_str) {
    struct tm tm = {};
    strptime(date_str.c_str(), "%Y%m%d", &tm);
    return tm;
}

