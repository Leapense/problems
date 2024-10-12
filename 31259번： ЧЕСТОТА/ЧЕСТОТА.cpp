#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> freq(26, 0);  // Initialize frequency array for 26 letters
    
    // Read input and count frequencies
    char ch;
    while (cin.get(ch) && ch != '@') {
        if (isalpha(ch)) {
            ch = toupper(ch);  // Convert to uppercase
            freq[ch - 'A']++;  // Increment the corresponding letter frequency
        }
    }
    
    // Find the maximum frequency
    int max_freq = *max_element(freq.begin(), freq.end());
    
    // Print the histogram
    for (int i = max_freq; i > 0; --i) {  // Start from max_freq down to 1
        for (int j = 0; j < 26; ++j) {
            if (freq[j] >= i)
                cout << char('A' + j) << "";  // Print the letter corresponding to the frequency
            else
                cout << " ";  // Print a space if the letter's frequency is less than the current level
        }
        cout << endl;
    }
    
    // Print the separator line
    for (int i = 0; i < 26; ++i) {
        cout << "-";
    }
    cout << endl;
    
    // Print the alphabet letters
    for (int i = 0; i < 26; ++i) {
        cout << char('A' + i) << "";
    }
    cout << endl;

    return 0;
}
