#include <iostream>
using namespace std;

// Compute days from MLC date (b, k, t, u, n)
long long computeMLCDays(int b, int k, int t, int u, int n) {
    return 144000LL * b + 7200 * k + 360 * t + 20 * u + n;
}

int main() {
    int K; // Number of data sets
    cin >> K;
    
    // The correct total days until the end of the MLC cycle at 13.0.0.0.0
    long long endMLCdays = 1872000; // Updated to reflect correct cycle completion
    long long todayJDN = 2456054; // JDN for 5/6/2012 G
    
    for (int dataSet = 1; dataSet <= K; dataSet++) {
        int b, k, t, u, n;
        cin >> b >> k >> t >> u >> n; // Read the MLC date
        long long eventMLCdays = computeMLCDays(b, k, t, u, n);
        
        long long eventJDN;
        cin >> eventJDN; // Read the JDN for the same event
        
        // Calculate the JDN for the end of the world (13.0.0.0.0 MLC)
        long long endJDN = eventJDN + (endMLCdays - eventMLCdays);
        
        // Days until the end of the world
        long long daysUntilEnd = endJDN - todayJDN;
        
        // Print result for this data set
        cout << "Data Set " << dataSet << ":\n";
        if (daysUntilEnd > 0) {
            cout << daysUntilEnd << "\n";
        } else if (daysUntilEnd == 0) {
            cout << "Panic!\n";
        } else {
            cout << "It's a hoax!\n";
        }
        cout << "\n"; // Blank line after each data set
    }
    
    return 0;
}
