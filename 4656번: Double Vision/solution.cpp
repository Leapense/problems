// solution.cpp
// C++26, compile with -std=c++26
#include <bits/stdc++.h>
using namespace std;

// r ≤ 10, c ≤ ~79 ⇒ r*c ≤ 790
static constexpr int MAX_PIXELS = 800;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c, tc = 1;
    while ( (cin >> n >> r >> c) ){
        if (n==0 && r==0 && c==0) break;
        vector<vector<string>> grid(n, vector<string>(r));
        for(int i=0;i<r;i++){
            for(int j=0;j<n;j++){
                cin >> grid[j][i];
            }
        }

        vector< bitset<MAX_PIXELS> > bits(n);
        for(int k=0;k<n;k++){
            bits[k].reset();
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if (grid[k][i][j]=='o')
                        bits[k].set(i*c + j);
                }
            }
        }

        // count how many symbols have each pixel
        vector<int> cnt(r*c, 0);
        for(int p=0;p<r*c;p++)
            for(int k=0;k<n;k++)
                if(bits[k].test(p))
                    ++cnt[p];

        vector<int> one(n, -1), two_p(n, -1), two_q(n, -1);
        bool ok = true;
        for(int k=0;k<n && ok;k++){
            // try one-pixel
            for(int p=0;p<r*c;p++){
                if(bits[k].test(p) && cnt[p]==1){
                    one[k]=p;
                    break;
                }
            }
            if(one[k]!=-1) continue;

            // try two-pixel
            bool found=false;
            for(int p=0;p<r*c && !found;p++){
                if(!bits[k].test(p)) continue;
                for(int q=p+1;q<r*c;q++){
                    if(!bits[k].test(q)) continue;
                    bool conflict=false;
                    for(int o=0;o<n;o++){
                        if(o==k) continue;
                        if(bits[o].test(p) && bits[o].test(q)){
                            conflict=true;
                            break;
                        }
                    }
                    if(!conflict){
                        two_p[k]=p;
                        two_q[k]=q;
                        found=true;
                        break;
                    }
                }
            }
            if(!found) ok=false;
        }

        cout << "Test " << tc++ << "\n";
        if(!ok){
            cout << "impossible\n";
            continue;
        }
        // output with '#'
        for(int i=0;i<r;i++){
            for(int k=0;k<n;k++){
                for(int j=0;j<c;j++){
                    int pos = i*c + j;
                    if(pos==one[k] || pos==two_p[k] || pos==two_q[k])
                        cout << '#';
                    else
                        cout << grid[k][i][j];
                }
                if(k+1<n) cout << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}
