#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, x;
    cin >> s >> x;
    
    vector<int> coefficients(s);
    for(int i = 0; i < s; ++i) {
        cin >> coefficients[i];
    }

    // Horner's method for polynomial evaluation mod 1000
    int result = 0;
    for(int i = 0; i < s; ++i) {
        result = (result * x + coefficients[i]) % 1000;
        if(result < 0) result += 1000; // Ensure result is non-negative
    }

    // Output the last three digits
    printf("%03d\n", result);

    return 0;
}