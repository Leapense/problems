#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>

std::string run_solution(const std::string &input)
{
    std::ofstream temp_in("temp_input.txt");
    temp_in << input;
    temp_in.close();

    std::string command = "./solution < temp_input.txt > temp_output.txt";
    std::ifstream check_executable("./solution");

    if (!check_executable)
    {
    }
    check_executable.close();

    int ret = system(command.c_str());
    if (ret != 0)
    {
        return "Execution failed or solution not found.";
    }

    std::ifstream temp_out("temp_output.txt");
    std::stringstream ss_out;
    ss_out << temp_out.rdbuf();
    temp_out.close();

    remove("temp_input.txt");
    remove("temp_output.txt");

    std::string result = ss_out.str();
    if (!result.empty() && result.back() == '\n')
    {
        result.pop_back();
    }
    return result;
}

TEST(AutobusTest, Sample1)
{
    std::string input = R"(4
Zagreb-Graz 15:30--23:59
Graz-Wroclaw 10:42--19:15
Zagreb-Graz 14:13--20:19
Graz-Wroclaw 2:25--5:00
)";
    std::string expected_output = "13:31";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, Sample2)
{
    std::string input = R"(3
Zagreb-Graz 6:05--16:40
Zagreb-Graz 20:00--21:40
Zagreb-Graz 9:56--22:36
)";
    std::string expected_output = "NEMOGUCE";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, ImmediateTransfer)
{
    std::string input = R"(2
Zagreb-Graz 10:00--10:59
Graz-Wroclaw 11:00--12:00
)";
    std::string expected_output = "2:01";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, ZGArrivesLateGWDepartsEarlyNextDay)
{
    std::string input = R"(2
Zagreb-Graz 22:00--23:58
Graz-Wroclaw 0:30--2:00
)";
    std::string expected_output = "4:01";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, NoZGRoutes)
{
    std::string input = R"(1
Graz-Wroclaw 10:00--12:00
)";
    std::string expected_output = "NEMOGUCE";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, NoGWRoutes)
{
    std::string input = R"(1
Zagreb-Graz 10:00--12:00
)";
    std::string expected_output = "NEMOGUCE";
    ASSERT_EQ(run_solution(input), expected_output);
}

TEST(AutobusTest, SingleZGAndSingleGW_LongWait)
{
    std::string input = R"(2
Zagreb-Graz 8:00--10:00
Graz-Wroclaw 15:00--17:00
)";
    std::string expected_output = "9:01";
    ASSERT_EQ(run_solution(input), expected_output);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}