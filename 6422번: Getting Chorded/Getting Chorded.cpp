#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> noteToInt = {
        {"A", 0}, {"A#", 1}, {"BB", 1}, {"B", 2}, {"CB", 2}, {"C", 3}, {"B#", 3}, {"C#", 4}, {"DB", 4}, {"D", 5}, {"D#", 6}, {"EB", 6}, {"E", 7}, {"FB", 7}, {"F", 8}, {"E#", 8}, {"F#", 9}, {"GB", 9}, {"G", 10}, {"G#", 11}, {"AB", 11}};
    vector<string> intToNote = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    string line;
    while (getline(cin, line))
    {
        if (line.find_first_not_of(" \t\r\n") == string::npos)
            break;
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> token)
            tokens.push_back(token);
        string normalized;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (i)
                normalized += " ";
            normalized += tokens[i];
        }
        vector<int> notes;
        for (auto s : tokens)
        {
            string t;
            for (auto c : s)
            {
                if (c == 'b')
                    t.push_back('B');
                else
                    t.push_back(toupper(c));
            }
            notes.push_back(noteToInt[t]);
        }
        bool recognized = false;
        string chordName = "", chordType = "";
        vector<int> perm = notes;
        sort(perm.begin(), perm.end());
        do
        {
            int first = perm[0], second = perm[1], third = perm[2];
            int interval1 = (second - first + 12) % 12;
            int interval2 = (third - second + 12) % 12;
            if (interval1 == 4 && interval2 == 3)
            {
                chordName = intToNote[first];
                chordType = "Major";
                recognized = true;
                break;
            }
            if (interval1 == 3 && interval2 == 4)
            {
                chordName = intToNote[first];
                chordType = "Minor";
                recognized = true;
                break;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        cout << normalized;
        if (recognized)
            cout << " is a " << chordName << " " << chordType << " chord.";
        else
            cout << " is unrecognized.";
        cout << "\n";
    }
    return 0;
}
