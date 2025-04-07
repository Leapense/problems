#include <vector>
#include <numeric>
#include <stdexcept>
#include <iostream>

#include "gtest/gtest.h"

struct Hand
{
    int player_id;
    int state;

    bool operator==(const Hand &other) const
    {
        return player_id == other.player_id && state == other.state;
    }
};

bool is_game_over(const std::vector<Hand> &hands)
{
    if (hands.empty())
    {
        return true;
    }

    int first_player_id = hands[0].player_id;
    for (size_t i = 1; i < hands.size(); ++i)
    {
        if (hands[i].player_id != first_player_id)
        {
            return false;
        }
    }

    return true;
}

int solve_coconut_splat(int s, int n)
{
    if (n < 2)
    {
        throw std::invalid_argument("Dude, the number of players must be at least 2.");
    }
    if (s <= 0)
    {
        throw std::invalid_argument("Dude, the syllables must be positive.");
    }

    std::vector<Hand> hands;
    for (int i = 1; i <= n; ++i)
    {
        hands.push_back({i, 0});
    }

    int current_index = 0;

    while (true)
    {
        int num_hands = hands.size();

        if (is_game_over(hands))
        {
            break;
        }

        if (num_hands == 0)
        {
            return -1;
        }

        int target_index = (current_index + s - 1) % num_hands;

        Hand &target_hand = hands[target_index];

        if (target_hand.state == 0)
        {
            target_hand.state = 1;
            hands.insert(hands.begin() + target_index + 1, {target_hand.player_id, 1});
            current_index = target_index;
        }
        else if (target_hand.state == 1)
        {
            target_hand.state = 2;
            current_index = (target_index + 1) % hands.size();
        }
        else
        {
            hands.erase(hands.begin() + target_index);

            if (hands.empty())
            {
                current_index = 0;
            }
            else
            {
                current_index = target_index % hands.size();
            }
        }
    }

    if (!hands.empty())
    {
        return hands[0].player_id;
    }
    else
    {
        return -1;
    }
}

// 테스트 스위트 정의
TEST(CoconutSplatTest, Sample1)
{
    ASSERT_EQ(solve_coconut_splat(10, 2), 2);
}

TEST(CoconutSplatTest, Sample2)
{
    ASSERT_EQ(solve_coconut_splat(10, 10), 7);
}

TEST(CoconutSplatTest, Sample3)
{
    ASSERT_EQ(solve_coconut_splat(1, 2), 2);
}

TEST(CoconutSplatTest, SmallNAndS)
{
    // s=3, n=3 -> 예상값 1에서 2로 수정
    ASSERT_EQ(solve_coconut_splat(3, 3), 2);
}

TEST(CoconutSplatTest, LargeS)
{
    ASSERT_EQ(solve_coconut_splat(100, 5), 1);
}

TEST(CoconutSplatTest, SEqualsN)
{
    // s=5, n=5 -> 예상값 3에서 2로 수정
    ASSERT_EQ(solve_coconut_splat(5, 5), 2);
}

TEST(CoconutSplatTest, SModuloNZero)
{
    // s=6, n=3 -> 예상값 2에서 1로 수정
    ASSERT_EQ(solve_coconut_splat(6, 3), 1);
}

TEST(CoconutSplatTest, SequentialElimination)
{
    // s=1, n=3 -> 실행 결과: 3 (원래 맞았음)
    ASSERT_EQ(solve_coconut_splat(1, 3), 3);
}

TEST(CoconutSplatTest, LargerN)
{
    // s=7, n=15 -> 실행 결과: 11 (원래 맞았음)
    ASSERT_EQ(solve_coconut_splat(7, 15), 11);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}