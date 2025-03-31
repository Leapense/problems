#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>
#include <algorithm>

using namespace std;

struct Node {
    int depth;      // 앞의 '.'의 개수
    string text;    // 게시글의 실제 내용
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        
        vector<Node> nodes(n);
        // 입력 버퍼 개행 처리
        string dummy;
        getline(cin, dummy);
        
        for (int i = 0; i < n; i++){
            string line;
            getline(cin, line);
            int d = 0;
            while(d < (int)line.size() && line[d] == '.') d++;
            nodes[i] = {d, line.substr(d)};
        }
        
        // 부모 인덱스 구하기 (루트는 -1)
        vector<int> parent(n, -1);
        stack<int> st;
        st.push(0); // 루트
        parent[0] = -1;
        for (int i = 1; i < n; i++){
            int d = nodes[i].depth;
            // 스택 크기가 현재 깊이보다 크면 pop
            while((int)st.size() > d)
                st.pop();
            // 스택의 top이 현재 노드의 부모 (깊이는 d-1)
            parent[i] = st.top();
            st.push(i);
        }
        
        // 각 노드(루트 제외)가 부모의 자식 중 마지막인지 판단
        vector<bool> isLast(n, true);
        // 루트는 판단할 필요 없음
        for (int i = 1; i < n; i++){
            isLast[i] = true;
            for (int j = i + 1; j < n; j++){
                if(parent[j] == parent[i] && nodes[j].depth == nodes[i].depth) {
                    isLast[i] = false;
                    break;
                }
                // 노드 j의 깊이가 부모보다 작아지면 더 이상 같은 부모의 자식이 없으므로 break
                if(nodes[j].depth < nodes[i].depth) break;
            }
        }
        
        // 각 노드마다 정돈된 트리 뷰를 출력
        for (int i = 0; i < n; i++){
            if(nodes[i].depth == 0){
                cout << nodes[i].text << "\n";
            } else {
                // 깊이가 d인 노드는 접두어 길이가 (d-1)이다.
                string prefix = "";
                int d = nodes[i].depth;
                // 깊이 1부터 d-1까지의 조상을 찾는다.
                // 단, 루트(깊이 0)는 접두어에 포함하지 않는다.
                // 각 단계별로, 해당 단계의 조상이 마지막 답글이 아니면 '|'를, 마지막 답글이면 ' '를 출력.
                for (int level = 1; level < d; level++){
                    // 현재 노드 i에서 깊이가 level인 조상을 찾는다.
                    int cur = i;
                    while(cur != -1 && nodes[cur].depth != level){
                        cur = parent[cur];
                    }
                    // cur가 반드시 존재함 (입력 형식에 보장됨)
                    assert(cur != -1);
                    if(!isLast[cur])
                        prefix.push_back('|');
                    else
                        prefix.push_back(' ');
                }
                // 마지막 접두어 위치에는 항상 '+'를 붙임
                cout << prefix << "+" << nodes[i].text << "\n";
            }
        }
    }
    
    return 0;
}


