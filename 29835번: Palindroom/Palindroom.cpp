#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string input;

    cin >> N;
    cin >> input;

    int replacements = 0;
    string palindrome = input;

    for (int i = 0; i < N / 2; ++i) {
        char left = palindrome[i];
        char right = palindrome[N - i - 1];

        if (left != right) {
            replacements++;

            char chosenChar = min(left, right);
            palindrome[i] = chosenChar;
            palindrome[N - 1 - i] = chosenChar;
        }
    }

    cout << replacements << endl;
    cout << palindrome << endl;

    return 0;
}