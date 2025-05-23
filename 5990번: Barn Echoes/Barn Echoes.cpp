#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the maximum overlap length between two strings
int max_overlap(const string& str1, const string& str2) {
    int max_overlap_length = 0;
    
    // Check overlap of suffix of str1 with prefix of str2
    for (int i = 1; i <= min(str1.length(), str2.length()); ++i) {
        if (str1.substr(str1.length() - i, i) == str2.substr(0, i)) {
            max_overlap_length = i;
        }
    }
    
    // Check overlap of suffix of str2 with prefix of str1
    for (int i = 1; i <= min(str1.length(), str2.length()); ++i) {
        if (str2.substr(str2.length() - i, i) == str1.substr(0, i)) {
            max_overlap_length = max(max_overlap_length, i);
        }
    }
    
    return max_overlap_length;
}

int main() {
    string str1, str2;

    // Reading input strings
    cin >> str1 >> str2;

    // Calculating and printing the maximum overlap length
    cout << max_overlap(str1, str2) << endl;

    return 0;
}