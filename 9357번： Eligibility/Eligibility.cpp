#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    cin.ignore();
    for(int tc=1; tc<=T; tc++){
        int N;
        cin>>N;
        cin.ignore();
        map<string, set<int>> m;
        for(int i=0;i<N;i++){
            string line;
            getline(cin,line);
            if(line.empty()){
                i--;
                continue;
            }
            size_t pos = line.find_last_of(' ');
            string name = line.substr(0,pos);
            int year = stoi(line.substr(pos+1));
            m[name].insert(year);
        }
        vector<string> eligible;
        for(auto &[name, years]:m){
            if(years.size() <5){
                eligible.push_back(name);
            }
        }
        sort(eligible.begin(), eligible.end());
        cout<<"Case #"<<tc<<":\n";
        for(auto &name:eligible){
            cout<<name<<"\n";
        }
    }
}