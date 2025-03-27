#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>

using namespace std;

unsigned long long parse_num(const string &s, unsigned long long base)
{
    unsigned long long result = 0;
    for (char c : s)
    {
        int digit;
        if (isdigit(c))
        {
            digit = c - '0';
        }
        else
        {
            digit = tolower(c) - 'a' + 10;
        }
        if (result > (ULLONG_MAX - digit) / base)
        {
            return ULLONG_MAX;
        }
        result = result * base + digit;
    }
    return result;
}

unsigned long long find_possible_base(const string &s, unsigned long long x)
{
    int max_digit = 0;
    for (char c : s)
    {
        int digit;
        if (isdigit(c))
        {
            digit = c - '0';
        }
        else
        {
            digit = tolower(c) - 'a' + 10;
        }
        if (digit > max_digit)
        {
            max_digit = digit;
        }
    }
    unsigned long long low = max_digit + 1;
    if (low < 2)
        low = 2;
    unsigned long long high = 36;
    if (s.size() > 1)
    {
        high = ULLONG_MAX;
    }
    vector<unsigned long long> possible_bases;
    while (low <= high)
    {
        unsigned long long mid = low + (high - low) / 2;
        unsigned long long num = parse_num(s, mid);
        if (num == x)
        {
            possible_bases.push_back(mid);
            unsigned long long temp = mid - 1;
            while (temp >= low && parse_num(s, temp) == x)
            {
                possible_bases.push_back(temp);
                temp--;
            }
            temp = mid + 1;
            while (temp <= high && parse_num(s, temp) == x)
            {
                possible_bases.push_back(temp);
                temp++;
            }
            break;
        }
        else if (num < x)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0)
                break;
            high = mid - 1;
        }
    }
    if (possible_bases.empty())
        return 0;
    sort(possible_bases.begin(), possible_bases.end());
    possible_bases.erase(unique(possible_bases.begin(), possible_bases.end()), possible_bases.end());
    if (possible_bases.size() > 1)
        return -1;
    return possible_bases[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a_str, b_str;
    cin >> a_str >> b_str;
    vector<pair<unsigned long long, pair<int, int>>> solutions;
    int max_digit_a = 0;
    for (char c : a_str)
    {
        int digit;
        if (isdigit(c))
        {
            digit = c - '0';
        }
        else
        {
            digit = tolower(c) - 'a' + 10;
        }
        if (digit > max_digit_a)
        {
            max_digit_a = digit;
        }
    }
    int max_digit_b = 0;
    for (char c : b_str)
    {
        int digit;
        if (isdigit(c))
        {
            digit = c - '0';
        }
        else
        {
            digit = tolower(c) - 'a' + 10;
        }
        if (digit > max_digit_b)
        {
            max_digit_b = digit;
        }
    }
    unsigned long long low_a = max_digit_a + 1;
    if (low_a < 2)
        low_a = 2;
    unsigned long long high_a = 36;
    unsigned long long low_b = max_digit_b + 1;
    if (low_b < 2)
        low_b = 2;
    unsigned long long high_b = 36;
    for (unsigned long long a = low_a; a <= high_a; ++a)
    {
        unsigned long long x = parse_num(a_str, a);
        if (x == ULLONG_MAX)
            continue;
        unsigned long long b = find_possible_base(b_str, x);
        if (b == 0)
            continue;
        if (b == -1)
        {
            cout << "Multiple\n";
            return 0;
        }
        if (a == b)
            continue;
        if (b >= 2 && b <= 36)
        {
            solutions.emplace_back(x, make_pair(a, b));
        }
    }
    for (unsigned long long b = low_b; b <= high_b; ++b)
    {
        unsigned long long x = parse_num(b_str, b);
        if (x == ULLONG_MAX)
            continue;
        unsigned long long a = find_possible_base(a_str, x);
        if (a == 0)
            continue;
        if (a == -1)
        {
            cout << "Multiple\n";
            return 0;
        }
        if (a == b)
            continue;
        if (a >= 2 && a <= 36)
        {
            solutions.emplace_back(x, make_pair(a, b));
        }
    }
    sort(solutions.begin(), solutions.end());
    solutions.erase(unique(solutions.begin(), solutions.end()), solutions.end());
    if (solutions.empty())
    {
        if (a_str == "0" && b_str == "0")
        {
            cout << "Multiple\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
    else if (solutions.size() > 1)
    {
        bool all_same = true;
        for (size_t i = 1; i < solutions.size(); ++i)
        {
            if (solutions[i].first != solutions[0].first)
            {
                all_same = false;
                break;
            }
        }
        if (all_same)
        {
            cout << solutions[0].first << " " << solutions[0].second.first << " " << solutions[0].second.second << "\n";
        }
        else
        {
            cout << "Multiple\n";
        }
    }
    else
    {
        cout << solutions[0].first << " " << solutions[0].second.first << " " << solutions[0].second.second << "\n";
    }
    return 0;
}