#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "gtest/gtest.h"
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> ages(N);
    for(int i=0;i<N;i++){
        int G, M, D;
        cin >> G >> M >> D;
        ages[i] = G * 400 + M * 30 + D;
    }
    vector<int> tmp = ages;
    sort(tmp.begin(), tmp.end(), greater<int>());
    int T = tmp[K-1];
    int countGreater = 0;
    for(auto v : ages) if(v > T) countGreater++;
    int need = K - countGreater;
    int vaccCount = 0, rejectCount = 0;
    for(int i = 0; i < N && vaccCount < K; i++){
        if(ages[i] > T){
            vaccCount++;
            continue;
        }
        if(ages[i] == T){
            if(need > 0){
                vaccCount++;
                need--;
                continue;
            }
            else {
                rejectCount++;
            }
        }
        else {
            rejectCount++;
        }
    }
    cout << rejectCount;
}

string runTest(const string &inputStr){
    stringstream input(inputStr), output;
    auto cinbuf = cin.rdbuf();
    auto coutbuf = cout.rdbuf();
    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());
    solve();
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return output.str();
}

TEST(CTest, Sample1){
    string input = "3 2\n3 3 3\n2 2 2\n1 1 1\n";
    string expected = "0";
    EXPECT_EQ(runTest(input), expected);
}

TEST(CTest, Sample2){
    string input = "3 1\n1 2 3\n2 3 4\n3 4 5\n";
    string expected = "2";
    EXPECT_EQ(runTest(input), expected);
}

TEST(CTest, Sample3){
    string input = "4 2\n21 2 0\n21 1 1\n21 2 1\n21 1 0\n";
    string expected = "1";
    EXPECT_EQ(runTest(input), expected);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

