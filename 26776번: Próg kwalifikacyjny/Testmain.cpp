// qualifier_test.cpp
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solve(const vector<long long>& V, const vector<long long>& Q){
    int N = V.size();
    vector<long long> A = V;
    sort(A.begin(), A.end(), greater<>());
    vector<long long> pref(N);
    pref[0] = A[0];
    for(int i = 1; i < N; i++) pref[i] = pref[i-1] + A[i];
    vector<int> ans;
    ans.reserve(Q.size());
    for(auto p : Q){
        int i = lower_bound(pref.begin(), pref.end(), p) - pref.begin();
        ans.push_back(i + 1);
    }
    return ans;
}

TEST(QualifierTest, Sample1){
    vector<long long> V = {3,2,1,1,5,1};
    vector<long long> Q = {3,13,9};
    vector<int> E = {1,6,3};
    EXPECT_EQ(solve(V,Q), E);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

