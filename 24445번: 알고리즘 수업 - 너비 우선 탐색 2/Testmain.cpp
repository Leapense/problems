#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include "gtest/gtest.h"
using namespace std;

void solve (istream& in, ostream& out) {
    int N, M, R;
    in >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        in >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    vector<int> order(N + 1, 0);
    queue<int> q;

    order[R] = 1;
    q.push(R);
    int visitOrder = 2;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (order[next] == 0) {
                order[next] = visitOrder++;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        out << order[i] << "\n";
    }
}

TEST(BFSTest, SampleTestCase1) {
    istringstream input(
        "5 5 1\n"
        "1 4\n"
        "1 2\n"
        "2 3\n"
        "2 4\n"
        "3 4\n"
    );
    ostringstream output;

    solve(input, output);

    string expected =
        "1\n"
        "3\n"
        "4\n"
        "2\n"
        "0\n";

    EXPECT_EQ(output.str(), expected);
}

class DetailedTestListener : public ::testing::EmptyTestEventListener {
    public:
        void OnTestStart(const ::testing::TestInfo& test_info) override {
            cout << "[START] " << test_info.test_suite_name() << "." << test_info.name() << "\n";
        }

        void OnTestPartResult(const ::testing::TestPartResult& test_part_result) override {
            if (test_part_result.failed()) {
                cout << "[FAIL] "
                     << test_part_result.file_name() << ":"
                     << test_part_result.line_number() << "\n"
                     << test_part_result.summary() << "\n";
            }
        }

        void OnTestEnd(const ::testing::TestInfo& test_info) override {
            cout << "[END] " << test_info.test_suite_name() << "." << test_info.name();

            if (test_info.result()->Passed()) {
                cout << " (PASSED)";
            } else {
                cout << " (FAILED)";
            }

            cout << "\n";
        }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new DetailedTestListener());

    int testResult = RUN_ALL_TESTS();

    return testResult;
}
