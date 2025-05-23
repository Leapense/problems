#include <iostream>
#include <vector>

using namespace std;

// Function to find the largest power of 2 less than or equal to n
long long largestPowerOf2LessThanOrEqualTo(long long n) {
    if (n <= 2) return 1;
    else return 3;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long n;
        cin >> n;
        
        // Find the largest power of 2 less than or equal to n
        long long largestPower = largestPowerOf2LessThanOrEqualTo(n);
        
        cout << largestPower << endl;
    }
    
    return 0;
}