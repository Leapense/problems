#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

using namespace std;

string getKey(const string &word) {
    int len = word.size();
    if (len <= 2) return word;
    string mid = word.substr(1, len - 2);
    sort(mid.begin(), mid.end());
    return word.front() + mid + word.back();
}

void solve(istream &in, ostream &out) {
    int N;
    in >> N;

    unordered_map<string, string> dict;
    for (int i = 0; i < N; i++) {
        string word;
        in >> word;
        string key = getKey(word);
        dict[key] = word;
    }

    int M;
    in >> M;

    vector<string> result;
    result.reserve(M);

    for (int i = 0; i < M; i++) {
        string scrambled;
        in >> scrambled;
        string key = getKey(scrambled);
        result.push_back(dict[key]);
    }

    for (size_t i = 0; i < result.size(); i++) {
        out << result[i] << (i < result.size() - 1 ? " " : "\n");
    }
}

#ifndef UNIT_TEST
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif

#ifdef UNIT_TEST
TEST(WordTest, GetKeyTest) {
    // 길이가 1, 2 인 단어는 그대로 반환되어야 함
    EXPECT_EQ(getKey("i"), "i");
    EXPECT_EQ(getKey("it"), "it");

    // 길이가 4인 단어 "love"의 경우, 중간 "ov" 정렬 후 그대로 "love"
    EXPECT_EQ(getKey("love"), "love");

    // "tihs"의 경우, 't' + sort("ih") + 's' = "this" 이어야 함
    EXPECT_EQ(getKey("tihs"), "this");
}

TEST(SampleTest, SampleInput1) {
    string input = R"(4
i
love
this
car
4
i love tihs car
)";
    string expectedOutput = "i love this car\n";
    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expectedOutput);
}

TEST(SampleTest, SampleInput2) {
    string input = R"(5
marvel
tony
stark
black
widow
5
mvearl tnoy stark bcalk wdiow
)";
    string expectedOutput = "marvel tony stark black widow\n";
    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expectedOutput);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif