#include <gtest/gtest.h>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 실제로 해결 코드를 담고 있는 solution.cpp 를 컴파일해서
// 여기와 링크해야 합니다.
extern int solve();

/// 입력 문자열을 main() 에 흘려보내고,
/// stdout 에 찍힌 내용을 한 줄씩 vector<string> 으로 돌려준다.
static vector<string> runWithInput(const string &input)
{
    // 임시 파일로 stdin 대체
    FILE *in = tmpfile();

    if (in == nullptr)
    {
        throw std::runtime_error("tmpfile() failed");
    }

    fwrite(input.data(), 1, input.size(), in);
    fflush(in);
    rewind(in);
    FILE *old_stdin = stdin;
    stdin = in;

    // cout → ostringstream
    ostringstream oss;
    auto *old_buf = cout.rdbuf(oss.rdbuf());

    solve();

    // 복원
    cout.rdbuf(old_buf);
    stdin = old_stdin;
    fclose(in);

    // 라인 단위로 자르기
    vector<string> lines;
    istringstream out(oss.str());
    string line;
    while (getline(out, line))
        lines.push_back(line);
    return lines;
}

TEST(TabUiSample, Sample1)
{
    std::string in =
        "10\n"
        "2\n2\n2\n2\n2\n2\n2\n2\n2\n2\n"   // 10개의 길이 2
        "10\n"                             // 화면 L=10
        "10\n"                             // Q=10
        "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"; // 클릭 순서
    auto out = runWithInput(in);
    ASSERT_EQ(out.size(), 10);
    EXPECT_EQ(out[0], "0.00");
    EXPECT_EQ(out[3], "2.00");  // 4번째 클릭 후
    EXPECT_EQ(out[7], "10.00"); // 8번째 클릭 후
    EXPECT_EQ(out[9], "10.00"); // 10번째 클릭 후
}

TEST(TabUiSample, Sample2)
{
    std::string in =
        "4\n"
        "2\n2\n2\n2\n"  // 4개의 길이 2
        "10\n"          // 화면 L=10
        "4\n"           // Q=4
        "1\n2\n3\n4\n"; // 클릭 순서
    auto out = runWithInput(in);
    ASSERT_EQ(out.size(), 4);
    for (auto &ln : out)
    {
        EXPECT_EQ(ln, "0.00");
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}