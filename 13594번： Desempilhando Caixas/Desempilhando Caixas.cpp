#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int N,P;
        cin>>N>>P;
        if(N==0 && P==0) break;
        vector<vector<int>> stacks(P, vector<int>());
        int s_box=0, s_pos=0;
        for(int i=0;i<P;i++){
            int Qi;
            cin>>Qi;
            stacks[i].reserve(Qi);
            for(int j=0;j<Qi;j++){
                int box;
                cin>>box;
                stacks[i].push_back(box);
                if(box ==1){
                    s_box = i;
                    s_pos = j+1;
                }
            }
        }
        int Qi = stacks[s_box].size();
        int remove_from_s = Qi - s_pos;
        int L = s_pos;
        // Left side
        int left_remove=0;
        if(s_box >0){
            int size_sl = stacks[s_box-1].size();
            left_remove = max(0, size_sl - (L-1));
        }
        // Right side
        int right_remove=0;
        if(s_box < P-1){
            int size_sr = stacks[s_box+1].size();
            right_remove = max(0, size_sr - (L-1));
        }
        int min_side = INT32_MAX;
        if(s_box >0 && s_box < P-1){
            min_side = min(left_remove, right_remove);
        }
        else{
            min_side = max(left_remove, right_remove);
        }
        // If only one side exists
        if(s_box ==0){
            min_side = right_remove;
        }
        if(s_box == P-1){
            min_side = left_remove;
        }
        int total = remove_from_s + min_side;
        cout<<total<<"\n";
    }
}
