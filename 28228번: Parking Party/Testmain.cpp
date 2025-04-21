#include "gtest/gtest.h"
#include <vector>
#include <string>

using namespace std;

int maxPark(const vector<string>& g){
    int n = g.size(), m = g[0].size();
    vector<vector<int>> L(n, vector<int>(m)), R(n, vector<int>(m)),
                        U(n, vector<int>(m)), D(n, vector<int>(m));
    vector<vector<char>> ok(n, vector<char>(m, 0));
    for(int i=0;i<n;i++){
        int last=0;
        for(int j=0;j<m;j++){
            if(g[i][j]=='o') last=j+1;
            else L[i][j]=last;
        }
        last=m+1;
        for(int j=m-1;j>=0;j--){
            if(g[i][j]=='o') last=j+1;
            else R[i][j]=last;
        }
        for(int j=0;j<m;j++) if(g[i][j]=='.' && (L[i][j]==0 || R[i][j]==m+1))
            ok[i][j]=1;
    }
    for(int j=0;j<m;j++){
        int last=0;
        for(int i=0;i<n;i++){
            if(g[i][j]=='o') last=i+1;
            else U[i][j]=last;
        }
        last=n+1;
        for(int i=n-1;i>=0;i--){
            if(g[i][j]=='o') last=i+1;
            else D[i][j]=last;
        }
        for(int i=0;i<n;i++) if(g[i][j]=='.' && (U[i][j]==0 || D[i][j]==n+1))
            ok[i][j]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(g[i][j]=='.' && ok[i][j]) cnt++;
    return cnt;
}

TEST(ParkingPartyTest, Sample1) {
    vector<string> g = {
        ".o.",
        "o.o",
        ".o."
    };
    EXPECT_EQ(maxPark(g), 4);
}

TEST(ParkingPartyTest, Sample2) {
    vector<string> g = {
        "oooo",
        "....",
        "...o"
    };
    EXPECT_EQ(maxPark(g), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
