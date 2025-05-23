#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> computeAB(const vector<int>& candidate, const vector<int>& code) {
    int c = candidate.size();
    int A = 0, B = 0;
    vector<bool> matched_candidate(c, false);
    vector<bool> matched_code(c, false);

    for (int i = 0; i < c; ++i) {
        if (candidate[i] == code[i]) {
            A += candidate[i];
            matched_candidate[i] = true;
            matched_code[i] = true;
        }
    }

    for (int i = 0; i < c; ++i) {
        if (!matched_candidate[i]) {
            for (int j = 0; j < c; ++j) {
                if (!matched_code[j] && candidate[i] == code[j]) {
                    B += candidate[i];
                    matched_code[j] = true;
                    break;
                }
            }
        }
    }

    return make_pair(A, B);
}

int main() {
    int c;
    cin >> c;
    vector<pair<int, int>> AB_values(c);
    vector<vector<int>> codes(c, vector<int>(c));

    for (int i = 0; i < c; ++i) {
        int A, B;
        cin >> A >> B;
        AB_values[i] = make_pair(A, B);
        for(int j = 0; j < c; ++j) {
            cin >> codes[i][j];
        }
    }

    vector<int> digits = {1,2,3,4,5,6,7,8,9};
    do {
        vector<int> candidate(digits.begin(), digits.begin() + c);

        bool is_valid = true;
        for (int i = 0; i < c; ++i) {
            pair<int, int> AB = computeAB(candidate, codes[i]);
            if (AB != AB_values[i]) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            for (int i = 0; i < c; ++i) {
                cout << candidate[i];
                if(i != c - 1) cout << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(digits.begin(), digits.end()));

    return 0;
}