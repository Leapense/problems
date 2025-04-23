#include <bits/stdc++.h>
using namespace std;
struct Msg{
    unsigned char type;
    int receiver;
    unsigned char flags;
};
static inline bool getbit(unsigned char f,int b){return f>>b&1;}
static inline void setbit(unsigned char& f,int b,bool v){if(v)f|=1u<<b;else f&=~(1u<<b);}
void solve(istream& in,ostream& out){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    in>>n>>q;
    vector<int> role(n+1);
    int director=0;
    for(int i=1;i<=n;++i){
        in>>role[i];
        if(role[i]==0)director=i;
    }
    long long globalS2T=0;
    vector<long long> personal(n+1,0);
    vector<Msg> msg(1);
    msg.reserve(q+1);
    for(int i=0;i<q;++i){
        int t;
        in>>t;
        if(t==1){
            int a,b;
            in>>a>>b;
            int sr=role[a],rr=role[b];
            if(sr==2&&rr==1){
                Msg m{1,0,0};
                setbit(m.flags,1,true);
                setbit(m.flags,2,true);
                msg.push_back(m);
                globalS2T++;
                personal[director]++;
            }else if(sr==1&&rr==2){
                Msg m{2,b,0};
                setbit(m.flags,0,true);
                setbit(m.flags,1,true);
                msg.push_back(m);
                personal[b]++;
                personal[director]++;
            }else{
                Msg m{0,b,0};
                setbit(m.flags,0,true);
                msg.push_back(m);
                personal[b]++;
            }
        }else if(t==2){
            int a,id;
            in>>a>>id;
            Msg& m=msg[id];
            if(m.type==0){
                if(a==m.receiver&&getbit(m.flags,0)){
                    setbit(m.flags,0,false);
                    personal[a]--;
                }
            }else if(m.type==2){
                if(a==m.receiver&&getbit(m.flags,0)){
                    setbit(m.flags,0,false);
                    personal[a]--;
                }else if(a==director&&getbit(m.flags,1)){
                    setbit(m.flags,1,false);
                    personal[director]--;
                }
            }else{
                if(role[a]==1&&getbit(m.flags,2)){
                    setbit(m.flags,2,false);
                    globalS2T--;
                }else if(a==director&&getbit(m.flags,1)){
                    setbit(m.flags,1,false);
                    personal[director]--;
                }
            }
        }else{
            int a;
            in>>a;
            long long res=personal[a];
            if(role[a]==1)res+=globalS2T;
            out<<res<<"\n";
        }
    }
}

#ifndef UNIT_TEST
int main(){
    solve(cin,cout);
    return 0;
}
#endif
