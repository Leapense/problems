#include <string>
#include <vector>
#include <stdexcept>
#include "gtest/gtest.h"

long long solve(const std::string& parentheses_string) {
    long long total_distance_sum = 0;
    std::vector<int> node_stack;

    if (parentheses_string.length() < 2 || parentheses_string.front() != '(' || parentheses_string.back() != ')') {

    }

    for (int i = 0; i < parentheses_string.length(); ++i) {
        if (parentheses_string[i] == '(') {
            node_stack.push_back(0);
        } else {
            if (node_stack.empty()) {
                return -1;
            }
            node_stack.pop_back();

            if (i > 0 && parentheses_string[i - 1] == '(') {
                total_distance_sum += node_stack.size();
            }
        }
    }

    if (!node_stack.empty()) {
        return -1;
    }

    return total_distance_sum;
}

class ParenthesesTreeTest : public ::testing::Test {
    protected:
        // You can put setup/teardown logic here if needed
};

TEST_F(ParenthesesTreeTest, Sample1) {
    ASSERT_EQ(solve("((()()())())"), 7);
}

// Test Case: Sample 2 from the problem description
TEST_F(ParenthesesTreeTest, Sample2) {
    ASSERT_EQ(solve("(()((()(()))()))"), 10);
}

// Test Case: Base case - single node tree
TEST_F(ParenthesesTreeTest, BaseCaseSingleNode) {
    ASSERT_EQ(solve("()"), 0);
}

// Test Case: Simple tree - root with one leaf child
TEST_F(ParenthesesTreeTest, SimpleTreeOneLeaf) {
    ASSERT_EQ(solve("(())"), 1);
}

// Test Case: Simple tree - root with two leaf children
TEST_F(ParenthesesTreeTest, SimpleTreeTwoLeaves) {
    ASSERT_EQ(solve("(()())"), 2); // Leaf 1 at dist 1, Leaf 2 at dist 1. Sum = 1 + 1 = 2
}

// Test Case: Deeper linear tree
TEST_F(ParenthesesTreeTest, LinearDeepTree) {
    ASSERT_EQ(solve("((((()))))"), 4); // Root -> C1 -> C2 -> C3 -> Leaf (dist 4)
}

// Test Case: Mixed structure 1
TEST_F(ParenthesesTreeTest, MixedStructure1) {
    // Root -> Leaf1 (dist 1), Child2 (dist 1) -> Leaf3 (dist 2)
    // Leaves at dist 1 and 2. Sum = 1 + 2 = 3
    ASSERT_EQ(solve("(()(()))"), 3);
}

// Test Case: Mixed structure 2 - sibling subtrees
TEST_F(ParenthesesTreeTest, MixedStructure2) {
    // Root -> (Node A -> Leaf C (dist 2)), (Node B -> Leaf D (dist 2))
    // Leaves C and D both at distance 2. Sum = 2 + 2 = 4
    ASSERT_EQ(solve("((()))(())"), 4);
}

// Test Case: Wider tree at level 1
TEST_F(ParenthesesTreeTest, WideTreeLevel1) {
    // Root -> Leaf1, Leaf2, Leaf3, Leaf4 (all dist 1)
    ASSERT_EQ(solve("(()()()())"), 4); // 1 + 1 + 1 + 1 = 4
}

// Test Case: More complex structure
TEST_F(ParenthesesTreeTest, ComplexStructure1) {
    // Root -> (NodeA -> (LeafB@2, LeafC@2)), (NodeD -> (NodeE -> LeafF@3))
    // Tree: ( ( () () ) ( ( () ) ) )
    // Leaves at distances 2, 2, 3. Sum = 2 + 2 + 3 = 7
    ASSERT_EQ(solve("((()())((())))"), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}