#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    long long num;
    int usedDigits;
};

int main() {
    vector<long long> repeatlessNumbers;
    queue<Node> q;
    for (int i = 1; i <= 9; ++i) {
        q.push({i, 1 << i});
        repeatlessNumbers.push_back(i);
    }

    while(repeatlessNumbers.size() < 1000000) {
        Node curr = q.front();
        q.pop();
        for (int d = 0; d <= 9; ++d) {
            if ((curr.usedDigits & (1 << d)) == 0) {
                long long newNum = curr.num * 10 + d;
                int newUsedDigits = curr.usedDigits | (1 << d);
                q.push({newNum, newUsedDigits});
                repeatlessNumbers.push_back(newNum);
                if (repeatlessNumbers.size() == 1000000) {
                    break;
                }
            }
        }
    }
    int n;
    while(cin >> n && n != 0) {
        cout << repeatlessNumbers[n - 1] << endl;
    }

    return 0;
}