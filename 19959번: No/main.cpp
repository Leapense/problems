#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

// Main solution: Reads the grid, precomputes circle offsets, and outputs the largest valid circle (moon)
int mainSolution()
{
    int w, h;
    cin >> w >> h;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }

    // Maximum possible radius to consider (at most the smaller of the dimensions)
    int maxPossible = min(w, h);
    // Precompute for each radius r the offsets (dx, dy) where dx^2 + dy^2 <= r^2.
    vector<vector<pair<int, int>>> offsets(maxPossible + 1);
    for (int r = 0; r <= maxPossible; r++)
    {
        for (int dy = -r; dy <= r; dy++)
        {
            int maxDx = (int)floor(sqrt(r * r - dy * dy));
            for (int dx = -maxDx; dx <= maxDx; dx++)
            {
                offsets[r].push_back({dx, dy});
            }
        }
    }

    // Try each radius from largest to smallest.
    for (int r = maxPossible; r >= 0; r--)
    {
        // The center must be chosen so that the circle is fully inside the image.
        for (int cy = r; cy < h - r; cy++)
        {
            for (int cx = r; cx < w - r; cx++)
            {
                bool valid = true;
                for (auto [dx, dy] : offsets[r])
                {
                    int x = cx + dx;
                    int y = cy + dy;
                    if (grid[y][x] != '*')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    // Output: radius on the first line and the 1-indexed center coordinates on the second.
                    cout << r << "\n"
                         << cx + 1 << " " << cy + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return mainSolution();
}
#else
// -------------------------
// Unit Testing using gtest
// -------------------------
#include <gtest/gtest.h>

// Helper function: Checks if the circle with given center (0-indexed) and radius r is valid on the grid.
bool isValidCircle(const vector<string> &grid, int cx, int cy, int r)
{
    int h = grid.size();
    int w = grid[0].size();
    // Check boundaries.
    if (cx - r < 0 || cx + r >= w || cy - r < 0 || cy + r >= h)
        return false;
    // Check every point in the circle.
    for (int dy = -r; dy <= r; dy++)
    {
        int maxDx = (int)floor(sqrt(r * r - dy * dy));
        for (int dx = -maxDx; dx <= maxDx; dx++)
        {
            int x = cx + dx, y = cy + dy;
            if (grid[y][x] != '*')
                return false;
        }
    }
    return true;
}

// Helper function: Parses the output into (radius, cx, cy)
tuple<int, int, int> parseOutput(const string &output)
{
    stringstream ss(output);
    int r, cx, cy;
    ss >> r >> cx >> cy;
    return {r, cx, cy};
}

// Test case for the first sample input.
TEST(MoonDetection, SampleTest1)
{
    string input = R"(7 8
.*.*...
.*****.
.*****.
*******
.*****.
.*****.
...*...
......*
)";
    vector<string> grid = {
        ".*.*...",
        ".*****.",
        ".*****.",
        "*******",
        ".*****.",
        ".*****.",
        "...*...",
        "......*"};

    stringstream ss(input);
    streambuf *origCin = cin.rdbuf();
    cin.rdbuf(ss.rdbuf());

    // Capture the output.
    stringstream output;
    streambuf *origCout = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    mainSolution();

    // Restore streams.
    cout.rdbuf(origCout);
    cin.rdbuf(origCin);

    string result = output.str();
    int r, cx, cy;
    tie(r, cx, cy) = parseOutput(result);

    // For this sample, the maximum radius is expected to be 3.
    ASSERT_EQ(r, 3) << "Expected maximum radius of 3";

    // Convert center from 1-indexed to 0-indexed.
    int centerX = cx - 1;
    int centerY = cy - 1;

    // Validate the reported circle.
    ASSERT_TRUE(isValidCircle(grid, centerX, centerY, r)) << "The circle defined by the output is not valid.";
}

// Test case for the second sample input.
TEST(MoonDetection, SampleTest2)
{
    string input = R"(5 4
.....
.....
..*..
.*...
)";
    vector<string> grid = {
        ".....",
        ".....",
        "..*..",
        ".*..."};

    stringstream ss(input);
    streambuf *origCin = cin.rdbuf();
    cin.rdbuf(ss.rdbuf());

    // Capture the output.
    stringstream output;
    streambuf *origCout = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    mainSolution();

    // Restore streams.
    cout.rdbuf(origCout);
    cin.rdbuf(origCin);

    string result = output.str();
    int r, cx, cy;
    tie(r, cx, cy) = parseOutput(result);

    // The expected maximum radius here is 0.
    ASSERT_EQ(r, 0) << "Expected radius of 0";

    // Convert center from 1-indexed to 0-indexed.
    int centerX = cx - 1;
    int centerY = cy - 1;

    // For r = 0, the pixel itself should be white.
    ASSERT_GE(centerX, 0);
    ASSERT_GE(centerY, 0);
    ASSERT_LT(centerY, (int)grid.size());
    ASSERT_LT(centerX, (int)grid[0].size());
    ASSERT_EQ(grid[centerY][centerX], '*') << "The pixel chosen as center is not white.";
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
