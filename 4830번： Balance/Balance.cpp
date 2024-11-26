#include <bits/stdc++.h>
using namespace std;

int main(){
    int NINSTRUMENTS, NTERMS, NREBALANCE;
    cin >> NINSTRUMENTS >> NTERMS >> NREBALANCE;
    vector<double> FIXED_FEE(NINSTRUMENTS);
    for(auto &x: FIXED_FEE) cin >> x;
    vector<double> PERCENTAGE_FEE(NINSTRUMENTS);
    for(auto &x: PERCENTAGE_FEE) cin >> x;
    vector<double> PRINCIPAL_START(NINSTRUMENTS);
    for(auto &x: PRINCIPAL_START) cin >> x;
    vector<vector<double>> RETURNS(NTERMS, vector<double>(NINSTRUMENTS));
    for(int i=0;i<NTERMS;i++) for(int j=0;j<NINSTRUMENTS;j++) cin >> RETURNS[i][j];
    vector<double> principals = PRINCIPAL_START;
    vector<bool> active(NINSTRUMENTS, true);
    vector<double> original_ratio(NINSTRUMENTS);
    double total_initial = 0.0;
    for(auto x: PRINCIPAL_START) total_initial += x;
    for(int j=0;j<NINSTRUMENTS;j++) original_ratio[j] = PRINCIPAL_START[j]/total_initial;
    for(int term=1; term<=NTERMS; term++){
        vector<double> temp = principals;
        for(int j=0; j<NINSTRUMENTS; j++){
            if(active[j]){
                temp[j] -= FIXED_FEE[j];
                temp[j] -= PERCENTAGE_FEE[j] * principals[j];
                temp[j] += RETURNS[term-1][j] * principals[j];
                if(temp[j] <= 1e-9){
                    temp[j] = 0.0;
                    active[j] = false;
                }
            }
        }
        principals = temp;
        if(term % NREBALANCE ==0 && term != NTERMS){
            double total = 0.0;
            for(auto x: principals) total += x;
            if(total > 0.0){
                for(int j=0; j<NINSTRUMENTS; j++) principals[j] = original_ratio[j] * total;
                for(int j=0; j<NINSTRUMENTS; j++) active[j] = principals[j] > 1e-9;
            }
        }
    }
    for(int j=0; j<NINSTRUMENTS; j++) {
        if(j>0) cout << ' ';
        // Corrected rounding without adding 0.5
        double rounded = round(principals[j]*100.0)/100.0;
        // To handle negative zero, ensure zero is printed as 0.00
        if(abs(rounded) < 1e-9) rounded = 0.0;
        cout << fixed << setprecision(2) << rounded;
    }
    cout << '\n';
}