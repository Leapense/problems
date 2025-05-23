#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 세그먼트 트리 노드 구조체
struct SegmentTreeNode {
    ll max_val;    // 구간 내 최대 빗물량
    ll lazy;       // 지연 업데이트 값

    SegmentTreeNode() : max_val(0), lazy(0) {}
};

// 세그먼트 트리 클래스
class SegmentTree {
private:
    int n; // 층의 개수
    vector<SegmentTreeNode> tree;

    // 내부적으로 사용하는 재귀 함수: 범위 업데이트
    void update_range(int node, int start, int end, int l, int r, ll val) {
        // 지연 업데이트가 있는 경우 처리
        if (tree[node].lazy != 0) {
            tree[node].max_val += tree[node].lazy;
            if (start != end) { // 리프 노드가 아닌 경우 자식에게 지연 업데이트 전달
                tree[2*node].lazy += tree[node].lazy;
                tree[2*node+1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }

        // 업데이트 범위가 현재 노드의 범위를 벗어나는 경우
        if (start > r || end < l)
            return;

        // 현재 노드의 범위가 업데이트 범위 내에 완전히 포함되는 경우
        if (start >= l && end <= r) {
            tree[node].max_val += val;
            if (start != end) {
                tree[2*node].lazy += val;
                tree[2*node+1].lazy += val;
            }
            return;
        }

        // 그렇지 않은 경우, 자식 노드로 나눠서 업데이트
        int mid = (start + end) / 2;
        update_range(2*node, start, mid, l, r, val);
        update_range(2*node+1, mid+1, end, l, r, val);

        // 부모 노드의 최대값 갱신
        tree[node].max_val = max(tree[2*node].max_val, tree[2*node+1].max_val);
    }

    // 내부적으로 사용하는 재귀 함수: 범위 내 최대값 조회
    ll query_max(int node, int start, int end, int l, int r) {
        // 지연 업데이트가 있는 경우 처리
        if (tree[node].lazy != 0) {
            tree[node].max_val += tree[node].lazy;
            if (start != end) {
                tree[2*node].lazy += tree[node].lazy;
                tree[2*node+1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }

        // 조회 범위가 현재 노드의 범위를 벗어나는 경우
        if (start > r || end < l)
            return LLONG_MIN;

        // 현재 노드의 범위가 조회 범위 내에 완전히 포함되는 경우
        if (start >= l && end <= r)
            return tree[node].max_val;

        // 그렇지 않은 경우, 자식 노드로 나눠서 조회
        int mid = (start + end) / 2;
        ll p1 = query_max(2*node, start, mid, l, r);
        ll p2 = query_max(2*node+1, mid+1, end, l, r);
        return max(p1, p2);
    }

    // 내부적으로 사용하는 재귀 함수: 특정 값 초과하는 인덱스 찾기
    int find_exceeding_floor(int node, int start, int end, ll K) {
        // 지연 업데이트가 있는 경우 처리
        if (tree[node].lazy != 0) {
            tree[node].max_val += tree[node].lazy;
            if (start != end) {
                tree[2*node].lazy += tree[node].lazy;
                tree[2*node+1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }

        // 현재 노드의 최대값이 K 이하인 경우
        if (tree[node].max_val <= K)
            return -1;

        // 리프 노드인 경우
        if (start == end)
            return start;

        // 자식 노드로 탐색
        int mid = (start + end) / 2;
        // 왼쪽 자식 먼저 탐색
        int res = find_exceeding_floor(2*node, start, mid, K);
        if (res != -1)
            return res;
        // 왼쪽에 없으면 오른쪽 자식 탐색
        return find_exceeding_floor(2*node+1, mid+1, end, K);
    }

public:
    // 생성자: 층의 개수를 받아 세그먼트 트리 초기화
    SegmentTree(int size) {
        n = size;
        tree.resize(4*n + 4);
    }

    // 범위 업데이트 함수: 1부터 t_i까지에 r_i 추가
    void add_rain(int l, int r, ll val) {
        update_range(1, 1, n, l, r, val);
    }

    // 범위 내 최대값 조회
    ll get_max(int l, int r) {
        return query_max(1, 1, n, l, r);
    }

    // K를 초과하는 층 중 하나의 인덱스 찾기
    int get_exceeding_floor(ll K) {
        return find_exceeding_floor(1, 1, n, K);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    SegmentTree st(N);
    
    bool collapsed = false;
    int collapse_event = -1;
    int collapse_floor = -1;
    
    for(int i=1; i<=M; ++i){
        int t_i;
        ll r_i;
        cin >> t_i >> r_i;
        
        // 1부터 t_i까지에 r_i 추가
        st.add_rain(1, t_i, r_i);
        
        // 1부터 t_i까지의 최대값 조회
        ll current_max = st.get_max(1, t_i);
        
        if(!collapsed && current_max > K){
            // K를 초과하는 층 중 하나의 인덱스 찾기
            int floor = st.get_exceeding_floor(K);
            if(floor != -1){
                collapsed = true;
                collapse_event = i;
                collapse_floor = floor;
            }
        }
    }
    
    if(collapsed){
        cout << collapse_event << " " << collapse_floor;
    }
    else{
        cout << "-1";
    }
}