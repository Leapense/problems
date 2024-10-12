#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n !=0){
        vector<int> a(n);
        vector<int> b(n);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        double pos_A=0.0, pos_B=0.0;
        int last_lead =0; // 0: no lead, 1: A, 2: B
        int overtake_count=0;
        for(int k=0; k<n; ++k){
            int speed_A = a[k];
            int speed_B = b[k];
            double pos_A_next = pos_A + speed_A;
            double pos_B_next = pos_B + speed_B;
            bool crossing = false;
            int new_lead = last_lead;
            if(speed_A != speed_B){
                double t = (pos_B - pos_A) / (double)(speed_A - speed_B);
                if(t > 0.0 && t <1.0){
                    crossing = true;
                    if(speed_A > speed_B){
                        // Runner B was leading before crossing, A after
                        new_lead =1;
                        if(last_lead ==2){
                            overtake_count +=1;
                        }
                    }
                    else{
                        // speed_A < speed_B
                        // Runner A was leading before crossing, B after
                        new_lead =2;
                        if(last_lead ==1){
                            overtake_count +=1;
                        }
                    }
                }
            }
            if(!crossing){
                if(pos_A_next > pos_B_next){
                    new_lead =1;
                }
                else if(pos_A_next < pos_B_next){
                    new_lead =2;
                }
                else{
                    new_lead =0;
                }
                if(new_lead !=0 && last_lead !=0 && new_lead != last_lead){
                    overtake_count +=1;
                }
            }
            if(new_lead !=0){
                last_lead = new_lead;
            }
            pos_A = pos_A_next;
            pos_B = pos_B_next;
        }
        cout << overtake_count << "\n";
    }
}