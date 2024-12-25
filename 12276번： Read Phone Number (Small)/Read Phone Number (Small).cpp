#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    string digit_words[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string count_prefix[11];
    count_prefix[2]="double";
    count_prefix[3]="triple";
    count_prefix[4]="quadruple";
    count_prefix[5]="quintuple";
    count_prefix[6]="sextuple";
    count_prefix[7]="septuple";
    count_prefix[8]="octuple";
    count_prefix[9]="nonuple";
    count_prefix[10]="decuple";
    for(int tc=1; tc<=T; tc++){
        string N, F;
        cin>>N>>F;
        vector<int> splits;
        int pos=0;
        while(pos < F.size()){
            int dash = F.find('-', pos);
            if(dash == string::npos){
                splits.push_back(stoi(F.substr(pos)));
                break;
            }
            splits.push_back(stoi(F.substr(pos, dash-pos)));
            pos = dash+1;
        }
        vector<string> parts;
        int start=0;
        for(auto s:splits){
            parts.push_back(N.substr(start, s));
            start +=s;
        }
        vector<string> words;
        for(auto part:parts){
            int n = part.size();
            int i=0;
            while(i<n){
                char current = part[i];
                int count=1;
                while(i+count<n && part[i+count]==current && count<10){
                    count++;
                }
                if(count>=2 && count<=10){
                    words.push_back(count_prefix[count]);
                    words.push_back(digit_words[current-'0']);
                    i +=count;
                }
                else{
                    words.push_back(digit_words[current-'0']);
                    i++;
                }
            }
        }
        string result = "";
        for(int i=0;i<words.size();i++){
            if(i>0) result += ' ';
            result += words[i];
        }
        cout<<"Case #"<<tc<<": "<<result<<"\n";
    }
}