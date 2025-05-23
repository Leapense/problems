#include<bits/stdc++.h>
using namespace std;

struct Measurement {
    int day;
    string name;
    int change;
};

int main(){
    int N;
    cin>>N;
    vector<Measurement> measurements(N);
    for(int i=0;i<N;i++) cin>>measurements[i].day>>measurements[i].name>>measurements[i].change;
    sort(measurements.begin(), measurements.end(), [&](const Measurement &a, const Measurement &b) -> bool{
        return a.day < b.day;
    });
    map<string, int> cows;
    cows["Bessie"]=7;
    cows["Elsie"]=7;
    cows["Mildred"]=7;
    set<string> previous_display = {"Bessie","Elsie","Mildred"};
    int count=0;
    for(auto &m: measurements){
        cows[m.name] += m.change;
        int max_output = max({cows["Bessie"], cows["Elsie"], cows["Mildred"]});
        set<string> current_display;
        for(auto &cow: cows){
            if(cow.second == max_output) current_display.insert(cow.first);
        }
        if(current_display != previous_display){
            count++;
            previous_display = current_display;
        }
    }
    cout<<count;
}