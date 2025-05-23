#include <bits/stdc++.h>
using namespace std;

string numToWords(int x) {
    vector<string> ones = {
        "", "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine"
    };
    vector<string> teens = {
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    vector<string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", 
        "sixty", "seventy", "eighty", "ninety"
    };

    if (x == 0) return "";

    string result;

    int hundred = x / 100;
    int remainder = x % 100;

    if (hundred > 0) {
        result += ones[hundred] + "hundred";
    }

    if (remainder > 0) {
        if (remainder < 10) {
            result += ones[remainder];
        } else if (remainder >= 10 && remainder <= 19) {
            result += teens[remainder - 10];
        } else {
            int t = remainder / 10;
            int o = remainder % 10;
            result += tens[t];
            if (o > 0) {
                result += ones[o];
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<string> words(N);
    int dollarPos = -1;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        if (words[i] == "$") {
            dollarPos = i;
        }
    }

    // We know there's always a solution and it's less than 1000.
    for (int num = 1; num < 1000; num++) {
        string numWord = numToWords(num);
        
        // Construct the sentence with this number
        vector<string> trial = words;
        trial[dollarPos] = numWord;
        
        // Count letters
        int letterCount = 0;
        for (auto &w : trial) {
            letterCount += (int)w.size();
        }

        if (letterCount == num) {
            // Print and finish
            for (int i = 0; i < N; i++) {
                cout << trial[i] << (i == N-1 ? '\n' : ' ');
            }
            break;
        }
    }

    return 0;
}