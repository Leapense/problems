#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string message, key_line;
    while(getline(cin, message)) {
        if (message.empty()) continue;
        if (!getline(cin, key_line)) break;

        stringstream ss(key_line);
        int k;
        
        ss >> k;
        vector<int> key(k);

        for (int i = 0; i < k; i++) ss >> key[i];

        vector<int> order_to_col(k + 1);
        for (int j = 0; j < k; j++) order_to_col[key[j]] = j;

        int n = message.size();
        int rows = (n + k - 1) / k;
        string cipher = "";

        for(int order = 1; order <= k; order++){
            int j = order_to_col[order];
            for(int r=0; r < rows; r++){
                int pos = r * k + j;
                if(pos < n){
                    cipher += message[pos];
                }
            }
        }
        cout << cipher << "\n";
    }

    return 0;
}