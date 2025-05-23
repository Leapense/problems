#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Date {
    int day, month, year;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
};

bool isLeap(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

Date nextDate(const Date& current) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Date next = current;

    if (current.month == 2 && isLeap(current.year)) daysInMonth[1] = 29;

    next.day += 1;

    if (next.day > daysInMonth[current.month - 1]) {
        next.day = 1;
        next.month += 1;

        if (next.month > 12) {
            next.month = 1;
            next.year += 1;
        }
    }

    return next;
}

string dateToString(const Date& date) {
    string s = "";

    if (date.day < 10) s += "0";
    s += to_string(date.day);
    s += ".";

    if (date.month < 10) s += "0";
    s += to_string(date.month);
    s += ".";

    if (date.year < 1000) s += "0";
    if (date.year < 100) s += "0";
    if (date.year < 10) s += "0";
    s += to_string(date.year);


    return s;
}

bool isValid(const string& s, const set<char>& allowed) {
    for (char c : s) {
        if (c == '.') continue;
        if (allowed.find(c) == allowed.end()) return false;
    }

    return true;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int k;
    cin >> k;

    set<char> allowed;

    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        allowed.insert(c);
    }

    string startStr, endStr;
    cin >> startStr >> endStr;

    Date start;
    start.day = stoi(startStr.substr(0, 2));
    start.month = stoi(startStr.substr(3, 2));
    start.year = stoi(startStr.substr(6, 4));

    Date end;
    end.day = stoi(endStr.substr(0, 2));
    end.month = stoi(endStr.substr(3, 2));
    end.year = stoi(endStr.substr(6, 4));

    int count = 0;
    Date current = start;

    while(!(current.year > end.year || (current.year == end.year && current.month > end.month) || (current.year == end.year && current.month == end.month && current.day > end.day))) {
        string s = "";

        if (current.day < 10) s += "0";
        s += to_string(current.day);
        s += ".";

        if (current.month < 10) s += "0";
        s += to_string(current.month);
        s += ".";

        if (current.year < 1000) s += "0";
        if (current.year < 100) s += "0";
        if (current.year < 10) s += "0";
        s += to_string(current.year);

        if (isValid(s, allowed)) {
            count++;
        }

        current = nextDate(current);
    }

    cout << count << "\n";

    return 0;
}