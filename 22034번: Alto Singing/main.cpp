#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
// 우연표(#)가 있는 음: 인덱스 1,3,6,8,10
const vector<bool> isAccidental = {false, true, false, true, false, false, true, false, true, false, true, false};

long long noteToPitch(const string &s)
{
    // 예: "C4" 혹은 "C#4"
    int idx = 0;
    if (s.size() >= 2 && s[1] == '#')
    {
        idx = 1; // 음이 2글자("C#")
    }
    else
    {
        idx = 0; // 음이 1글자("C")
    }
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
    // 피치 계산: (octave - 1) * 12 + noteIndex
    return (octave - 1) * 12LL + noteIndex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string lowestTone, highestTone;
    cin >> lowestTone >> highestTone;

    long long L = noteToPitch(lowestTone);
    long long R = noteToPitch(highestTone);

    vector<long long> piece(n);
    for (int i = 0; i < n; i++)
    {
        string tone;
        cin >> tone;
        piece[i] = noteToPitch(tone);
    }

    // 전조 t의 허용 범위 계산: 모든 p에 대해 t ∈ [L-p, R-p]
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

    // 각 residue (0~11)에 대해 우연표 개수 계산
    vector<int> accidentalCount(12, 0);
    for (int r = 0; r < 12; r++)
    {
        int cnt = 0;
        for (long long p : piece)
        {
            int noteAfter = (p + r) % 12;
            if (isAccidental[noteAfter])
                cnt++;
        }
        accidentalCount[r] = cnt;
    }

    // [T_min, T_max] 범위 내에서 residue r에 해당하는 t의 개수를 구하는 함수
    auto countTForResidue = [&](int r) -> long long
    {
        // T_min의 residue 구하기 (음수가 있을 수 있으므로 올바르게 계산)
        int modMin = (int)(((T_min % 12) + 12) % 12);
        long long firstT;
        if (modMin <= r)
        {
            firstT = T_min + (r - modMin);
        }
        else
        {
            firstT = T_min + (12 - (modMin - r));
        }
        if (firstT > T_max)
            return 0LL;

        int modMax = (int)(((T_max % 12) + 12) % 12);
        long long lastT;
        if (modMax >= r)
        {
            lastT = T_max - (modMax - r);
        }
        else
        {
            lastT = T_max - (12 - (r - modMax));
        }
        if (lastT < firstT)
            return 0LL;
        return ((lastT - firstT) / 12LL) + 1;
    };

    int bestAccidentals = 1e9;
    long long countBest = 0;

    // residue 0~11에 대해 최소 우연표와 해당 전조 개수를 산출
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

    cout << bestAccidentals << " " << countBest << "\n";

    return 0;
}
