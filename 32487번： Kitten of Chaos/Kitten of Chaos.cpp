#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Transform mappings
char horizontalMap[128];
char verticalMap[128];
char rotate180Map[128];

void initializeMappings() {
    horizontalMap['b'] = 'd';
    horizontalMap['d'] = 'b';
    horizontalMap['p'] = 'q';
    horizontalMap['q'] = 'p';

    verticalMap['b'] = 'p';
    verticalMap['d'] = 'q';
    verticalMap['p'] = 'b';
    verticalMap['q'] = 'd';

    rotate180Map['b'] = 'q';
    rotate180Map['d'] = 'p';
    rotate180Map['p'] = 'd';
    rotate180Map['q'] = 'b';
}

int main() {
    string s, t;
    cin >> s >> t;
    
    initializeMappings();

    int countH = 0, countV = 0, countR = 0;
    
    // Count occurrences of each transformation
    for (char trans : t) {
        if (trans == 'h') ++countH;
        else if (trans == 'v') ++countV;
        else if (trans == 'r') ++countR;
    }

    // Determine effective transformations
    bool doHorizontal = countH % 2 != 0;
    bool doVertical = countV % 2 != 0;
    bool doRotate = countR % 2 != 0;

    if (doRotate) {
        // Perform rotation by reversing string and applying rotate180Map to each character
        reverse(s.begin(), s.end());
        for (char &c : s) c = rotate180Map[c];
    }

    if (doHorizontal) {
        reverse(s.begin(), s.end());
        for (char &c : s) c = horizontalMap[c];
    }

    if (doVertical) {
        for (char &c : s) c = verticalMap[c];
    }

    cout << s << endl;

    return 0;
}
