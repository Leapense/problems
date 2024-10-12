#include <bits/stdc++.h>
using namespace std;

struct Muffin {
    long long price;
    long long count;
};

bool compare(Muffin a, Muffin b) {
    return a.price < b.price;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    long long prices[3], counts[3], money;
    for (int i = 0; i < 3; i++) cin >> prices[i];
    for (int i = 0; i < 3; i++) cin >> counts[i];

    cin >> money;

    vector<Muffin> muffins = {{prices[0], counts[0]}, {prices[1], counts[1]}, {prices[2], counts[2]}};
    sort(muffins.begin(), muffins.end(), compare);

    long long totalMuffins = 0;
    
    for (int i = 0; i < 3; i++) {
        if (muffins[i].price == 0) {
            totalMuffins += muffins[i].count;
            continue;
        }
        long long canBuy = min(money / muffins[i].price, muffins[i].count);
        totalMuffins += canBuy;
        money -= canBuy * muffins[i].price;
    }

    cout << totalMuffins << endl;

    return 0;
}