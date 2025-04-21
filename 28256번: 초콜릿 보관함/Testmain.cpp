#include <gtest/gtest.h>
#include <queue>
#include <sstream>
using namespace std;

void solve(istream& in, ostream& out) {
    int T;
    in >> T;
    while (T--) {
        vector<string> g(3);
        in >> g[0] >> g[1] >> g[2];
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) in >> a[i];
        vector<vector<bool>> vis(3, vector<bool>(3));
        vector<int> comps;
        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            if (i==1 && j==1) continue;
            if (!vis[i][j] && g[i][j]=='O') {
                int cnt=0;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[i][j]=true;
                while(!q.empty()){
                    auto [x,y]=q.front();q.pop();
                    cnt++;
                    for(int d=0;d<4;d++){
                        int nx=x+dx[d], ny=y+dy[d];
                        if(nx<0||nx>=3||ny<0||ny>=3) continue;
                        if(nx==1&&ny==1) continue;
                        if(!vis[nx][ny] && g[nx][ny]=='O'){
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                comps.push_back(cnt);
            }
        }
        sort(comps.begin(), comps.end());
        if (comps.size()==a.size() && comps==a) out << "1\n"; else out << "0\n";
    }
}

string run(const string& input) {
    istringstream in(input);
    ostringstream out;
    solve(in, out);
    return out.str();
}

TEST(ChocolateBoxTest, SampleCases) {
    string in =
        "6\n"
        "OOO\n"
        "O-O\n"
        "XOO\n"
        "1 7\n"
        "XOO\n"
        "O-O\n"
        "XXO\n"
        "2 1 4\n"
        "OXO\n"
        "O-X\n"
        "XXO\n"
        "3 1 1 2\n"
        "XOX\n"
        "O-O\n"
        "XOX\n"
        "4 1 1 1 1\n"
        "XOO\n"
        "O-O\n"
        "OOX\n"
        "1 6\n"
        "OXX\n"
        "O-O\n"
        "XXO\n"
        "3 1 1 2\n";
    string expected =
        "1\n"
        "1\n"
        "1\n"
        "1\n"
        "0\n"
        "0\n";
    EXPECT_EQ(run(in), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
