#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "main.h"
using namespace std;

const vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const vector<bool> isAccidental = {false, true, false, true, false, false, true, false, true, false, true, false};

long long noteToPitch(const string &s)
{
    int idx = (s.size() >= 2 && s[1] == '#') ? 1 : 0;
    string notePart = s.substr(0, idx + 1);
    long long octave = stoll(s.substr(idx + 1));

    int noteIndex = 0;
    for (int i = 0; i < 12; i++)
    {
        if (notes[i] == notePart)
        {
            noteIndex = i;
            break;
        }
    }
    return (octave - 1) * 12LL + noteIndex;
}

void solve(istream &in, ostream &out)
{
    int n;
    in >> n;

    string lowestTone, highestTone;
    in >> lowestTone >> highestTone;

    long long L = noteToPitch(lowestTone);
    long long R = noteToPitch(highestTone);

    vector<long long> piece(n);
    for (int i = 0; i < n; i++)
    {
        string tone;
        in >> tone;
        piece[i] = noteToPitch(tone);
    }

    long long T_min = 0, T_max = 0;
    bool first = true;

    for (long long p : piece)
    {
        long long lower = L - p;
        long long upper = R - p;
        if (first)
        {
            T_min = lower;
            T_max = upper;
            first = false;
        }
        else
        {
            T_min = max(T_min, lower);
            T_max = min(T_max, upper);
        }
    }

    vector<int> accidentalCount(12, 0);
    for (int r = 0; r < 12; r++)
    {
        int cnt = 0;
        for (long long p : piece)
        {
            int noteAfter = (p + r) % 12;
            if (isAccidental[noteAfter])
            {
                cnt++;
            }
        }
        accidentalCount[r] = cnt;
    }

    auto countTForResidue = [&](int r) -> long long
    {
        int modMin = (int)(((T_min % 12) + 12) % 12);
        long long firstT = (modMin <= r) ? T_min + (r - modMin) : T_min + (12 - (modMin - r));
        if (firstT > T_max)
            return 0LL;

        int modMax = (int)(((T_max % 12) + 12) % 12);
        long long lastT = (modMax >= r) ? T_max - (modMax - r) : T_max - (12 - (r - modMax));

        if (lastT < firstT)
            return 0LL;
        return ((lastT - firstT) / 12LL) + 1;
    };

    int bestAccidentals = 1e9;
    long long countBest = 0;

    for (int r = 0; r < 12; r++)
    {
        long long cntT = countTForResidue(r);
        if (cntT == 0)
            continue;
        if (accidentalCount[r] < bestAccidentals)
        {
            bestAccidentals = accidentalCount[r];
            countBest = cntT;
        }
        else if (accidentalCount[r] == bestAccidentals)
        {
            countBest += cntT;
        }
    }

    out << bestAccidentals << " " << countBest << "\n";
}

#ifndef UNIT_TESTS
int main()
{
    solve(cin, cout);
    return 0;
}
#endif