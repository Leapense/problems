#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
struct Node {
    long long val;
    int idx;
};
struct cmp {
    bool operator()(const Node &a, const Node &b) const {
        if(a.val == b.val) return a.idx > b.idx;
        return a.val < b.val;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> wealth(n);
    for(int i=0;i<n;i++) cin >> wealth[i];
    priority_queue<Node, vector<Node>, cmp> pq;
    for(int i=0;i<n;i++){
        if(wealth[i] > 100){
            pq.push({wealth[i], i});
        }
    }
    for(int i=0;i<k;i++){
        if(pq.empty()){
            cout << "impossible";
            return 0;
        }
        Node cur = pq.top();
        pq.pop();
        if(wealth[cur.idx] != cur.val) { i--; continue; }
        wealth[cur.idx] -= 100;
        if(wealth[cur.idx] > 100){
            pq.push({wealth[cur.idx], cur.idx});
        }
    }
    for(auto w : wealth) cout << w << " ";
    return 0;
}
