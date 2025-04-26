#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

extern int main(int, char **);

static std::string run(const std::string &in)
{
    std::FILE *inf = std::tmpfile();
    std::FILE *outf = std::tmpfile();
    fwrite(in.data(), 1, in.size(), inf);
    rewind(inf);
    int bak_stdin = dup(fileno(stdin));
    int bak_stdout = dup(fileno(stdout));

    dup2(fileno(inf), fileno(stdin));
    dup2(fileno(outf), fileno(stdout));

    main(0, nullptr);

    fflush(stdout);
    fseek(outf, 0, SEEK_END);

    long sz = ftell(outf);
    std::string out(sz, '\0');
    rewind(outf);

    fread(out.data(), 1, sz, outf);

    dup2(bak_stdin, fileno(stdin));
    dup2(bak_stdout, fileno(stdout));
    close(bak_stdin);
    close(bak_stdout);

    fclose(inf);
    fclose(outf);

    return out;
}

TEST(TreeDrawing, Sample1)
{
    std::string in =
        "4\n"
        "0 0\n"
        "-1 0\n"
        "1 1\n"
        "1 -1\n";
    auto out = run(in);
    std::istringstream iss(out);

    int u, v, cnt = 0;
    while (iss >> u >> v)
        ++cnt;

    ASSERT_EQ(cnt, 3);
}

TEST(TreeDrawing, Sample2)
{
    std::string in =
        "7\n"
        "1 1\n"
        "3 3\n"
        "4 0\n"
        "3 1\n"
        "4 -2\n"
        "6 -2\n"
        "4 -3\n";

    auto out = run(in);
    std::istringstream iss(out);
    int u, v, cnt = 0;
    while (iss >> u >> v)
        ++cnt;
    ASSERT_EQ(cnt, 6);
}