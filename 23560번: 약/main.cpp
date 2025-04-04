#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <algorithm>
using namespace std;

int N, total;

// 인덱스에 따른 약의 종류를 반환합니다.
// 인덱스 0 -> 'M' (아침), 1 -> 'L' (점심), 2 -> 'D' (저녁)
char getPill(int idx) {
    int mod = idx % 3;
    if(mod == 0) return 'M';
    else if(mod == 1) return 'L';
    else return 'D';
}

// 두 개의 큰 정수를 문자열 형태로 받아서 덧셈한 결과를 반환합니다.
string stringAdd(const string &a, const string &b) {
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string result;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if(j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        result.push_back('0' + (sum % 10));
    }
    reverse(result.begin(), result.end());
    return result;
}

// dp[l][r] : 남은 약 봉투가 l번째부터 r번째까지 있을 때의 경우의 수를 문자열로 저장
vector<vector<optional<string>>> dp;

// dp를 이용하여 [l, r] 구간에 대해 올바른 방법의 수를 계산합니다.
string solveDP(int l, int r) {
    if(l > r) return "1"; // 모든 약을 먹은 경우
    if(dp[l][r].has_value()) return dp[l][r].value();
    
    int k = total - (r - l + 1);
    bool isLunch = (k % 3 == 1); // k mod 3 == 1이면 점심 시간
    
    string ways = "0";
    if(l == r) {
        char pill = getPill(l);
        if(isLunch) {
            if(pill == 'L')
                ways = "1";
        } else {
            if(pill == 'M' || pill == 'D')
                ways = "1";
        }
        dp[l][r] = ways;
        return ways;
    }
    
    char leftPill = getPill(l);
    char rightPill = getPill(r);
    if(isLunch) {
        if(leftPill == 'L')
            ways = stringAdd(ways, solveDP(l + 1, r));
        if(rightPill == 'L')
            ways = stringAdd(ways, solveDP(l, r - 1));
    } else {
        if(leftPill == 'M' || leftPill == 'D')
            ways = stringAdd(ways, solveDP(l + 1, r));
        if(rightPill == 'M' || rightPill == 'D')
            ways = stringAdd(ways, solveDP(l, r - 1));
    }
    
    dp[l][r] = ways;
    return ways;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    total = 3 * N;
    dp.assign(total, vector<optional<string>>(total, nullopt));
    
    cout << solveDP(0, total - 1) << "\n";
    return 0;
}

