#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

string find_kings(const vector<long long>& a){
    int n=a.size();
    vector<pair<long long,int>> b(n);
    for(int i=0;i<n;i++) b[i]={a[i],i};
    sort(b.begin(),b.end());
    auto can_succeed=[&](int pos){
        long long sum=b[pos].first;
        for(int i=0;i<n;i++){
            if(i==pos) continue;
            if(sum<=b[i].first) return false;
            sum+=b[i].first;
        }
        return true;
    };
    int lo=0, hi=n-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(can_succeed(mid)) hi=mid;
        else lo=mid+1;
    }
    if(!can_succeed(lo)) return string(n,'N');
    string res(n,'N');
    for(int i=lo;i<n;i++) res[b[i].second]='T';
    return res;
}

TEST(SumyTest, Sample1) {
    vector<long long> a = {2, 7, 1, 8, 2, 8};
    EXPECT_EQ(find_kings(a), "NTNTNT");
}

TEST(SumyTest, Sample2) {
    vector<long long> a = {5, 4, 4};
    EXPECT_EQ(find_kings(a), "TNN");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
