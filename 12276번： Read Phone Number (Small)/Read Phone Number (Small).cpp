#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const string digitWords[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string countTerms[11] = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};

vector<int> getGroupSizes(const string& format) {
    vector<int> sizes;
    stringstream ss(format);
    string part;
    while (getline(ss, part, '-')) {
        sizes.push_back(stoi(part));
    }
    return sizes;
}

vector<string> splitIntoGroups(const string& N, const vector<int>& sizes) {
    vector<string> groups;
    int start = 0;
    for (int size : sizes) {
        groups.push_back(N.substr(start, size));
        start += size;
    }
    return groups;
}

string processGroup(const string& group) {
    vector<string> words;
    if (group.empty()) return "";
    char prev = group[0];
    int count = 1;
    for (size_t i = 1; i < group.size(); ++i) {
        if (group[i] == prev) {
            ++count;
            if (count == 10) {
                words.push_back(countTerms[10]);
                words.push_back(digitWords[prev - '0']);
                prev = group[i];
                count = 1;
            }
        } else {
            if (count == 1) {
                words.push_back(digitWords[prev - '0']);
            } else {
                words.push_back(countTerms[count]);
                words.push_back(digitWords[prev - '0']);
            }
            prev = group[i];
            count = 1;
        }
    }
    if (count == 1) {
        words.push_back(digitWords[prev - '0']);
    } else {
        words.push_back(countTerms[count]);
        words.push_back(digitWords[prev - '0']);
    }
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int x = 1; x <= T; ++x) {
        string line;
        getline(cin, line);
        while (line.empty()) {
            getline(cin, line);
        }
        size_t spacePos = line.find(' ');
        string N = line.substr(0, spacePos);
        string F = line.substr(spacePos + 1);
        vector<int> sizes = getGroupSizes(F);
        vector<string> groups = splitIntoGroups(N, sizes);
        vector<string> groupReadings;
        for (const string& group : groups) {
            string reading = processGroup(group);
            groupReadings.push_back(reading);
        }
        string result;
        for (size_t i = 0; i < groupReadings.size(); ++i) {
            result += groupReadings[i];
            if (i != groupReadings.size() - 1) {
                result += " ";
            }
        }
        cout << "Case #" << x << ": " << result << endl;
    }
    return 0;
}