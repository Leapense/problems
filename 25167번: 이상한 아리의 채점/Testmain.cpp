#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
int toMinutes(const string &s) {
    int h = stoi(s.substr(0, s.find(':')));
    int m = stoi(s.substr(s.find(':')+1));
    return h * 60 + m;
}
struct Record {
    int firstWrong = -1;
    int solveTime = -1;
    bool solvedValid = false;
    bool solvedInvalid = false;
    bool attempted = false;
};
void solve(istream &in, ostream &out) {
    int N, M, P;
    in >> N >> M >> P;
    vector<string> names(M);
    unordered_map<string,int> idx;
    for (int i = 0; i < M; i++) {
        in >> names[i];
        idx[names[i]] = i;
    }
    vector<vector<Record>> rec(N+1, vector<Record>(M));
    for (int i = 0; i < P; i++) {
        int prob;
        string time, name, result;
        in >> prob >> time >> name >> result;
        int t = toMinutes(time);
        int id = idx[name];
        Record &r = rec[prob][id];
        if(r.solvedValid || r.solvedInvalid) continue;
        r.attempted = true;
        if(result == "wrong") {
            if(r.firstWrong == -1) r.firstWrong = t;
        } else {
            if(r.firstWrong == -1) r.solvedInvalid = true;
            else {
                r.solvedValid = true;
                r.solveTime = t;
            }
        }
    }
    vector<int> total(M, 0);
    for (int prob = 1; prob <= N; prob++) {
        vector<tuple<int, string, int>> valid;
        for (int i = 0; i < M; i++) {
            if(rec[prob][i].solvedValid) {
                int dur = rec[prob][i].solveTime - rec[prob][i].firstWrong;
                valid.push_back({dur, names[i], i});
            }
        }
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if(get<0>(a) == get<0>(b))
                return get<1>(a) < get<1>(b);
            return get<0>(a) < get<0>(b);
        });
        vector<int> score(M, 0);
        for (int pos = 0; pos < (int)valid.size(); pos++) {
            int idxP = get<2>(valid[pos]);
            score[idxP] = pos + 1;
        }
        for (int i = 0; i < M; i++) {
            if(rec[prob][i].solvedValid) continue;
            if(rec[prob][i].solvedInvalid) score[i] = M + 1;
            else if(rec[prob][i].attempted) score[i] = M;
            else score[i] = M + 1;
        }
        for (int i = 0; i < M; i++) {
            total[i] += score[i];
        }
    }
    vector<pair<int, string>> result;
    for (int i = 0; i < M; i++) {
        result.push_back({total[i], names[i]});
    }
    sort(result.begin(), result.end(), [](auto &a, auto &b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    for(auto &p : result)
        out << p.second << "\n";
}
TEST(GTestSuite, SampleTest1) {
    string input = R"(2 4 10
ari betty cugi dori
1 10:00 ari wrong
1 10:05 ari solve
2 10:06 betty solve
2 10:10 cugi solve
2 10:15 betty wrong
1 10:20 cugi wrong
1 10:26 cugi wrong
1 10:30 cugi solve
2 10:35 betty solve
1 10:40 ari solve
)";
    string expected = R"(ari
cugi
betty
dori
)";
    istringstream iss(input);
    ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), expected);
}
TEST(GTestSuite, SampleTest2) {
    string input = R"(2 4 10
ari betty cugi dori
1 10:00 ari wrong
2 10:00 dori wrong
1 10:15 betty wrong
2 10:30 dori solve
1 10:30 betty wrong
1 11:00 betty solve
1 12:00 ari solve
2 13:00 ari wrong
2 14:00 cugi wrong
2 15:45 cugi solve
)";
    string expected = R"(ari
betty
dori
cugi
)";
    istringstream iss(input);
    ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), expected);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

