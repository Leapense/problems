#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        q.push(num);
    }
    
    stack<int> s;
    int expected = 1;
    
    while (!q.empty() || !s.empty()) {
        if (!q.empty() && q.front() == expected) {
            q.pop();
            expected++;
        } else if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        } else if (!q.empty()) {
            s.push(q.front());
            q.pop();
        } else {
            break;
        }
    }
    
    if (expected == N + 1) {
        cout << "Nice" << endl;
    } else {
        cout << "Sad" << endl;
    }
    
    return 0;
}