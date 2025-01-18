#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K, M;
    cin >> N >> K >> M;
    
    list<int> people;
    for(int i = 1; i <= N; ++i) people.push_back(i);
    
    vector<int> result;
    int direction = 1;
    int removed = 0;
    
    auto it = people.begin();
    for(int i = 1; i < K; ++i){
        if(it == people.end()) it = people.begin();
        ++it;
    }
    
    while(!people.empty()){
        result.push_back(*it);

        auto current = it;
        ++it;
        if(it == people.end()) it = people.begin();
        
        people.erase(current);
        removed++;
        
        if(people.empty()) break;
        
        if(removed % M == 0){
            direction *= -1;
        }

        if(direction == 1){
            for(int i = 1; i < K; ++i){
                ++it;
                if(it == people.end()) it = people.begin();
            }
        }
        else{
            if(it == people.begin()) it = people.end();
            --it;
            for(int i = 1; i < K; ++i){
                if(it == people.begin()) it = people.end();
                --it;
            }
        }
    }
    
    for(auto num: result) cout << num << "\n";

    return 0;
}