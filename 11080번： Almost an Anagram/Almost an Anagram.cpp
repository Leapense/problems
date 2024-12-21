#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequency(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    return freq;
}

bool isAnagram(const string &a, const string &b) {
    vector<int> freqA = getFrequency(a);
    vector<int> freqB = getFrequency(b);
    for (int i = 0; i < 26; i++) {
        if (freqA[i] != freqB[i]) return false;
    }

    return true;
}

bool isAlmostAnagramSameLength(const string &a, const string &b) {
    vector<int> freqA = getFrequency(a);
    vector<int> freqB = getFrequency(b);
    int mismatchSum = 0;

    for (int i = 0; i < 26; i++) {
        mismatchSum += abs(freqA[i] - freqB[i]);
        if (mismatchSum > 2) return false;
    }

    return (mismatchSum == 2);
}

bool isAlmostAnagramDiffLength(const string &smallStr, const string &bigStr) {
    if (bigStr.size() != smallStr.size() + 1) return false;
    vector<int> freqS = getFrequency(smallStr);
    vector<int> freqB = getFrequency(bigStr);
    int mismatchSum = 0;
    for (int i = 0; i < 26; i++) {
        mismatchSum += abs(freqB[i] - freqS[i]);
        if (mismatchSum > 1) return false;
    }
    return (mismatchSum == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string w1, w2;
    cin >> w1 >> w2;

    string wA = w1, wB = w2;

    if (w1.size() < w2.size()) {

    } else if (w1.size() > w2.size()) {
        wA = w2;
        wB = w1;
    } else {
        if (w2 < w1) {
            wA = w2;
            wB = w1;
        }
    }

    if (wA == wB) {
        cout << wA << " is identical to " << wB << "\n";
        return 0;
    }

    if (wA.size() == wB.size() && isAnagram(wA, wB)) {
        cout << wA << " is an anagram of " << wB << "\n";
        return 0;
    }

    if (abs((int)wA.size() - (int)wB.size()) == 1) {
        if (isAlmostAnagramDiffLength(wA, wB)) {
            cout << wA << " is almost an anagram of " << wB << "\n";
            return 0;
        }
    }
    else if (wA.size() == wB.size()) {
        if (isAlmostAnagramSameLength(wA, wB)) {
            cout << wA << " is almost an anagram of " << wB << "\n";
            return 0;
        }
    }

    cout << wA << " is nothing like " << wB << "\n";
    return 0;
}