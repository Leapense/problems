#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

// 펜윅 트리 (Binary Indexed Tree) 구현
struct Fenw
{
    int n;
    vector<long long> fenw;
    Fenw(int n) : n(n), fenw(n + 1, 0) {}
    void update(int i, long long delta)
    {
        for (; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    long long query(int i)
    {
        long long res = 0;
        for (; i > 0; i -= i & -i)
            res += fenw[i];
        return res;
    }
};

struct Event
{
    int type;
    long long x, p_or_y;
};

// solve 함수: istream에서 입력받아 ostream으로 출력
void solve(istream &in, ostream &out)
{
    ios::sync_with_stdio(false);
    in.tie(nullptr);

    int N, Q;
    in >> N >> Q;
    vector<Event> events;
    events.reserve(Q);
    for (int i = 0; i < Q; i++)
    {
        int t;
        long long x, p;
        in >> t >> x >> p;
        events.push_back({t, x, p});
    }

    // 좌표 압축: 상대 후보(1번~N번)의 초기 득표(0)와 업데이트 후 득표수를 모두 수집
    vector<long long> oppVotes(N + 1, 0); // 1-indexed, 후보 1 ~ N
    vector<long long> compVals;
    compVals.reserve(Q + N + 5);
    for (int i = 1; i <= N; i++)
    {
        compVals.push_back(0);
    }
    // 임시로 oppVotes를 업데이트하여 모든 등장하는 득표수를 compVals에 넣음
    for (auto &ev : events)
    {
        if (ev.type == 1)
        {
            int cand = (int)ev.p_or_y;
            if (cand <= N)
            { // 상대 후보
                long long newVal = oppVotes[cand] + ev.x;
                oppVotes[cand] = newVal;
                compVals.push_back(newVal);
            }
        }
    }
    // 좌표 압축 처리
    sort(compVals.begin(), compVals.end());
    compVals.erase(unique(compVals.begin(), compVals.end()), compVals.end());
    int compSize = compVals.size();

    // oppVotes를 다시 초기화 (후보 1~N은 0표부터 시작)
    fill(oppVotes.begin(), oppVotes.end(), 0);

    // 두 개의 펜윅 트리: 하나는 개수, 하나는 득표수 합계
    Fenw fenwCount(compSize), fenwSum(compSize);
    int idx0 = int(lower_bound(compVals.begin(), compVals.end(), 0) - compVals.begin()) + 1;
    for (int i = 1; i <= N; i++)
    {
        fenwCount.update(idx0, 1);
        fenwSum.update(idx0, 0);
    }

    // 정후(후보 번호 N+1)의 득표수
    long long myVotes = 0;
    vector<string> answers;
    answers.reserve(Q);

    // 이벤트 처리
    for (auto &ev : events)
    {
        if (ev.type == 1)
        {
            int cand = (int)ev.p_or_y;
            if (cand == N + 1)
            {
                // 정후의 득표수 갱신
                myVotes += ev.x;
            }
            else
            {
                // 상대 후보의 득표수 갱신: BIT 업데이트
                long long oldVal = oppVotes[cand];
                int oldIdx = int(lower_bound(compVals.begin(), compVals.end(), oldVal) - compVals.begin()) + 1;
                fenwCount.update(oldIdx, -1);
                fenwSum.update(oldIdx, -oldVal);

                long long newVal = oldVal + ev.x;
                oppVotes[cand] = newVal;
                int newIdx = int(lower_bound(compVals.begin(), compVals.end(), newVal) - compVals.begin()) + 1;
                fenwCount.update(newIdx, 1);
                fenwSum.update(newIdx, newVal);
            }
        }
        else
        {
            // 질의: 정후에게 추가로 x표, 상대 후보들에게 y표가 더 집계되었을 때
            long long addMy = ev.x, extraOpp = ev.p_or_y;
            long long finalMy = myVotes + addMy;
            if (finalMy <= 0)
            {
                answers.push_back("NO");
                continue;
            }
            long long threshold = finalMy - 1;
            int pos = int(upper_bound(compVals.begin(), compVals.end(), threshold) - compVals.begin());
            long long cnt = 0, sumVal = 0;
            if (pos > 0)
            {
                cnt = fenwCount.query(pos);
                sumVal = fenwSum.query(pos);
            }
            // 만약 threshold보다 큰 득표수를 가진 후보가 있다면 이미 정후보다 득표수가 크거나 같으므로 당선 불가능
            if (fenwCount.query(compSize) - cnt > 0)
            {
                answers.push_back("NO");
                continue;
            }
            long long capacity = cnt * threshold - sumVal;
            if (capacity >= extraOpp)
                answers.push_back("YES");
            else
                answers.push_back("NO");
        }
    }

    // 질의에 대한 결과 출력
    for (auto &ans : answers)
        out << ans << "\n";
}

// 아래는 gtest를 활용한 테스트 케이스들입니다.
TEST(SolutionTest, SampleTest)
{
    string input = R"(2 5
1 5 1
1 7 2
1 3 3
2 5 1
2 5 3
)";
    string expected_output = "YES\nNO\n";

    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(SolutionTest, OnlyMyVotesTest)
{
    // 정후에게만 투표가 들어온 경우 (정후는 후보 N+1)
    string input = R"(1 3
1 10 2
1 5 2
2 0 0
)";
    // 후보 1은 0표, 정후는 15표, 질의: 추가 표 없음 → 상대 후보가 모두 0표이므로 당선 가능 (threshold = 14, capacity = 14)
    string expected_output = "YES\n";

    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(SolutionTest, OpponentOvertakeTest)
{
    // 상대 후보 중 하나가 이미 정후의 득표수보다 많은 경우
    string input = R"(1 4
1 10 1
1 5 2
1 2 2
2 0 0
)";
    // 후보 1: 10표, 정후(후보 2): 7표 (5+2), 질의 시 정후 최종 7표,
    // 후보 1 이미 10표이므로 질의 결과는 NO.
    string expected_output = "NO\n";

    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(SolutionTest, ExtraVotesTest)
{
    // 질의 시 추가 표가 반영되어 당선 가능성이 바뀌는 경우
    string input = R"(2 6
1 4 1
1 3 2
1 2 3
2 5 5
1 1 1
2 0 0
)";
    // 이벤트별 상태:
    // 후보1: 4표, 후보2: 3표, 후보3: 2표, 정후: 0표.
    // 첫 질의: 정후 +5표 → 최종 5표, 질의 조건: 상대 후보들에게 추가 5표 분배 가능 여부
    // - threshold = 4, 후보1: 4, 후보2: 3, 후보3: 2 → 후보1 이미 4표이면 추가 득표 불가 (동점이면 결선) → NO.
    // 두 번째 질의: 그 이후, 후보1에 1표 추가 → 후보1: 5표, 정후: 5표, 질의: 추가 없음 → 상대 후보 중 후보1이 이미 5표이므로 NO.
    string expected_output = "NO\nNO\n";

    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
