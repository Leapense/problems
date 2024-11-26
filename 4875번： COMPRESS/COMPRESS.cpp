#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;
        size_t dash = line.find('-');
        string F_str = line.substr(0, dash);
        string R_str = line.substr(dash+1);
        long long F = stoll(F_str);
        long long R = stoll(R_str);
        int len_F = F_str.size();
        int len_R = R_str.size();
        int k_max = len_R;
        string C_str = "";
        for(int k=1; k<=k_max; k++){
            long long pow_k=1;
            for(int i=0;i<k;i++) pow_k *=10;
            long long C = R % pow_k;
            string C_temp = to_string(C);
            while(C_temp.size() < k) C_temp = "0" + C_temp;
            long long R_reconstructed;
            if(k <= len_F){
                long long last_k_F = F % pow_k;
                long long first_part_F = F / pow_k;
                if(C > last_k_F){
                    R_reconstructed = first_part_F * pow_k + C;
                }
                else{
                    R_reconstructed = (first_part_F +1)*pow_k + C;
                }
            }
            else{
                if(C > F){
                    R_reconstructed = C;
                }
                else{
                    R_reconstructed = C + pow_k;
                }
            }
            if(R_reconstructed == R){
                C_str = C_temp;
                break;
            }
        }
        cout << F << "-" << C_str << "\n";
    }
}