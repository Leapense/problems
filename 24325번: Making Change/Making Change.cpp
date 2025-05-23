#include <bits/stdc++.h>
using namespace std;

void calculateChange(int cost, int payment) {
    // Calculate the change amount in cents
    int change = payment - cost;

    // Define the bill values in cents
    vector<int> bills = {5000, 2000, 1000, 500, 100};
    vector<int> count(5, 0); // To store the count of each bill

    // Calculate the number of each bill needed
    for (int i = 0; i < bills.size(); ++i) {
        count[i] = change / bills[i];
        change %= bills[i];
    }

    // Print the result in the desired format
    cout << count[0] << "-$50, " << count[1] << "-$20, "
         << count[2] << "-$10, " << count[3] << "-$5, "
         << count[4] << "-$1" << endl;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double cost, payment;
        cin >> cost >> payment;

        int costCents = static_cast<int>(cost * 100 + 0.5);
        int paymentCents = static_cast<int>(payment * 100 + 0.5);

        calculateChange(costCents, paymentCents);
    }

    return 0;
}