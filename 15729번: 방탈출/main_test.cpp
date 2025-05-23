#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// Function to test (extracted from the original code)
int solveEscapeRoom(vector<int> target)
{
    int n = target.size();
    vector<int> state(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (state[i] != target[i])
        {
            count++;
            state[i] ^= 1;
            if (i + 1 < n)
                state[i + 1] ^= 1;
            if (i + 2 < n)
                state[i + 2] ^= 1;
        }
    }
    return count;
}

// Test cases
void testSolveEscapeRoom()
{
    // Test case 1: Empty input
    assert(solveEscapeRoom({}) == 0);

    // Test case 2: Single element, already correct
    assert(solveEscapeRoom({0}) == 0);

    // Test case 3: Single element, needs change
    assert(solveEscapeRoom({1}) == 1);

    // Test case 4: Two elements, needs change
    assert(solveEscapeRoom({1, 0}) == 1);

    // Test case 5: Two elements, needs change
    assert(solveEscapeRoom({1, 1}) == 1);

    // Test case 6: Three elements, needs change
    assert(solveEscapeRoom({1, 0, 0}) == 1);

    // Test case 7: Three elements, needs change
    assert(solveEscapeRoom({1, 1, 0}) == 1);

    // Test case 8: Three elements, needs change
    assert(solveEscapeRoom({1, 1, 1}) == 1);

    // Test case 9: Three elements, needs change
    assert(solveEscapeRoom({0, 1, 0}) == 1);

    // Test case 10: Three elements, needs change
    assert(solveEscapeRoom({0, 1, 1}) == 1);

    // Test case 11: Multiple elements, more complex
    assert(solveEscapeRoom({1, 0, 1, 0, 1}) == 3);

    // Test case 12: Multiple elements, more complex
    assert(solveEscapeRoom({1, 1, 0, 1, 0}) == 2);

    // Test case 13: Multiple elements, more complex
    assert(solveEscapeRoom({1, 1, 1, 1, 1}) == 1);

    // Test case 14: Multiple elements, more complex
    assert(solveEscapeRoom({0, 0, 0, 0, 0}) == 0);

    // Test case 15: Multiple elements, more complex
    assert(solveEscapeRoom({1, 0, 1, 0, 1, 0, 1}) == 4);

    // Test case 16: Multiple elements, more complex
    assert(solveEscapeRoom({1, 1, 1, 0, 0, 0, 1}) == 2);

    // Test case 17: Multiple elements, more complex
    assert(solveEscapeRoom({1, 0, 0, 1, 0, 0, 1}) == 3);

    // Test case 18: Multiple elements, more complex
    assert(solveEscapeRoom({1, 1, 0, 0, 1, 1, 0}) == 3);

    cout << "All test cases passed!" << endl;
}

int main()
{
    testSolveEscapeRoom();
    return 0;
}
