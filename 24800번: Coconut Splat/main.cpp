#include <iostream>
#include <vector>
#include <numeric>
#include <set>

struct Hand
{
    int player_id;
    int state;
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int s, n;
    std::cin >> s >> n;

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
            break;
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
        std::cout << hands[0].player_id << std::endl;
    }

    return 0;
}