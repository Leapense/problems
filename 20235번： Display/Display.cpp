#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100;
static const int MAXWH = 31;

int n, w, h;
long long s;
bool fontBmp[MAXN][MAXWH][MAXWH];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w >> h >> s;

    // 문자 저장
    vector<char> chars(n);
    // 폰트 읽기
    for(int i = 0; i < n; i++){
        cin >> ws;
        chars[i] = cin.get();
        for(int r = 0; r < h; r++){
            string line;
            cin >> line;
            for(int c = 0; c < w; c++){
                fontBmp[i][r][c] = (line[c] == '#');
            }
        }
    }

    vector<vector<string>> rowPat(n, vector<string>(h));
    for(int i = 0; i < n; i++){
        for(int r = 0; r < h; r++){
            string tmp;
            for(int c = 0; c < w; c++){
                tmp.push_back(fontBmp[i][r][c] ? '1' : '0');
            }
            tmp.push_back('0');
            rowPat[i][r] = tmp;
        }
    }
    vector<vector<int>> firstBit(n, vector<int>(h));
    vector<vector<int>> lastBit(n, vector<int>(h));
    vector<vector<int>> insideOne(n, vector<int>(h));

    for(int i = 0; i < n; i++){
        for(int r = 0; r < h; r++){
            const string &p = rowPat[i][r];
            int togg = 0;
            firstBit[i][r] = (p[0] == '1');
            for(int x = 1; x < (int)p.size(); x++){
                if(p[x] != p[x-1]) togg++;
            }
            insideOne[i][r] = togg;
            lastBit[i][r] = (p.back() == '1');
        }
    }
    auto solveKSingle = [&](int i){
        long long bestK = LLONG_MAX;
        for(int r = 0; r < h; r++){
            long long fb = firstBit[i][r];
            long long in = insideOne[i][r];
            long long lb = lastBit[i][r];
            long long bd = (lb != fb) ? 1 : 0;
            long long base = fb + in;
            long long cyc = in + bd;

            if(cyc == 0) {
                if(base >= s) {
                    bestK = min(bestK, 1LL);
                }
            } else {
                long long need = s - base;
                if(need <= 0) {
                    bestK = min(bestK, 1LL);
                } else {
                    long long tmp = (need + cyc - 1) / cyc;
                    long long candK = tmp + 1;
                    if(candK > 0) bestK = min(bestK, candK);
                }
            }
        }
        if(bestK == LLONG_MAX) return (long long)1e15;
        return bestK;
    };

    auto singleTogglesK = [&](int i, long long k){
        long long best = 0;
        for(int r=0; r<h; r++){
            long long fb = firstBit[i][r];
            long long in = insideOne[i][r];
            long long lb = lastBit[i][r];
            long long bd = (lb != fb) ? 1 : 0;
            if(k<=0) continue;
            long long val = fb + in;
            if(k>1) val += (k-1)*(in+bd);
            best = max(best, val);
        }
        return best;
    };

    static vector<vector<vector<int>>> firstAB(MAXN, vector<vector<int>>(MAXN, vector<int>(MAXWH)));
    static vector<vector<vector<int>>> insideAB(MAXN, vector<vector<int>>(MAXN, vector<int>(MAXWH)));
    static vector<vector<vector<int>>> lastAB(MAXN, vector<vector<int>>(MAXN, vector<int>(MAXWH)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int r = 0; r < h; r++){
                // AB: rowPat[i][r] + rowPat[j][r]
                string ab = rowPat[i][r] + rowPat[j][r];
                int togg = 0;
                firstAB[i][j][r] = (ab[0] == '1');
                for(int x = 1; x < (int)ab.size(); x++){
                    if(ab[x] != ab[x-1]) togg++;
                }
                insideAB[i][j][r] = togg;
                lastAB[i][j][r] = (ab.back() == '1');
            }
        }
    }

    auto solveKAB = [&](int i,int j){
        long long bestK = LLONG_MAX;
        for(int r = 0; r < h; r++){
            long long fb = firstAB[i][j][r];
            long long in = insideAB[i][j][r];
            long long lb = lastAB[i][j][r];
            long long bd = (lb != fb) ? 1 : 0;
            long long base = fb + in;
            long long cyc = in + bd;

            if(cyc == 0){
                if(base >= s){
                    bestK = min(bestK, 1LL);
                }
            } else {
                long long need = s - base;
                if(need <= 0){
                    bestK = min(bestK, 1LL);
                } else {
                    long long tmp = (need + cyc -1)/cyc;
                    long long candK = tmp+1;
                    if(candK>0) bestK=min(bestK,candK);
                }
            }
        }
        if(bestK==LLONG_MAX) return (long long)1e15;
        return bestK;
    };
    auto togglesABk = [&](int i,int j,long long k){
        long long best=0;
        if(k<=0) return 0LL;
        for(int r=0;r<h;r++){
            long long fb = firstAB[i][j][r];
            long long in = insideAB[i][j][r];
            long long lb = lastAB[i][j][r];
            long long bd = (lb != fb) ? 1 : 0;
            long long val = fb + in;
            if(k>1) val += (k-1)*(in+bd);
            best=max(best,val);
        }
        return best;
    };

    auto togglesABkPlusTail = [&](int i, int j, long long k, int tail){
        long long base = togglesABk(i,j,k);

        long long best = 0;

        for(int r=0;r<h;r++){
            long long fb = firstAB[i][j][r];
            long long in = insideAB[i][j][r];
            long long lb = lastAB[i][j][r];
            long long bd = (lb != fb)?1:0;

            long long ABk_tog = 0;
            long long endB = 0;
            if(k==0){
                ABk_tog = 0;
                endB = 0;
            } else {
                ABk_tog = fb + in + (k-1)*(in+bd);
                endB = lb; 
            }

            vector<int> seq;
            seq.push_back((int)endB);
            if(tail>=1){
                // + A (문자 i)
                for(int c=0;c<w;c++){
                    seq.push_back(fontBmp[i][r][c] ? 1 : 0);
                }
                seq.push_back(0);
            }
            if(tail==2){
                // + B (문자 j)
                for(int c=0;c<w;c++){
                    seq.push_back(fontBmp[j][r][c] ? 1 : 0);
                }
                seq.push_back(0); 
            }
            long long tailTog=0;
            for(int idx=1; idx<(int)seq.size(); idx++){
                if(seq[idx]!=seq[idx-1]) tailTog++;
            }

            long long rowTotal = ABk_tog + tailTog;
            best = max(best, rowTotal);
        }
        return max(base,best);
    };

    long long bestLen = LLONG_MAX;
    struct Info {
        int type;
        int i, j;
        long long k;
        int tail;
    };
    Info bestInfo = {0,-1,-1,0,0};

    // 1) 단일 문자
    for(int i=0; i<n; i++){
        long long k = solveKSingle(i);
        if(k >= (long long)1e14) continue;
        if(k <= s){
            long long t = singleTogglesK(i,k);
            if(t >= s){
                if(k < bestLen){
                    bestLen = k;
                    bestInfo = {1, i, -1, k, 0};
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            long long k = solveKAB(i,j);
            if(k >= (long long)1e14) continue;

            if(2LL*k <= s){
                long long t = togglesABk(i,j,k);
                if(t >= s){
                    if(2LL*k < bestLen){
                        bestLen = 2LL*k;
                        bestInfo = {2, i, j, k, 0};
                    }
                }
            }
            if(2LL*k + 1 <= s){
                long long t = togglesABkPlusTail(i,j,k,1);
                if(t >= s){
                    if(2LL*k + 1 < bestLen){
                        bestLen = 2LL*k + 1;
                        bestInfo = {2, i, j, k, 1};
                    }
                }
            }
            if(2LL*k + 2 <= s){
                long long t = togglesABkPlusTail(i,j,k,2);
                if(t >= s){
                    if(2LL*k + 2 < bestLen){
                        bestLen = 2LL*k + 2;
                        bestInfo = {2, i, j, k, 2};
                    }
                }
            }
        }
    }
    string answer;
    if(bestInfo.type == 1){
        answer.append(bestInfo.k, chars[bestInfo.i]);
    } else {
        for(int r=0; r<bestInfo.k; r++){
            answer.push_back(chars[bestInfo.i]);
            answer.push_back(chars[bestInfo.j]);
        }
        if(bestInfo.tail >= 1){
            answer.push_back(chars[bestInfo.i]);
        }
        if(bestInfo.tail == 2){
            answer.push_back(chars[bestInfo.j]);
        }
    }

    cout << answer << "\n";
    return 0;
}
