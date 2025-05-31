#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

const int MAX_PLAYERS_CONST = 1000;

void add_edge_cpp(int winner, int loser, int k, std::vector<std::vector<bool>>& adj_matrix_ref) {
    if (winner > 0 && winner <= k && loser > 0 && loser <= k) {
        adj_matrix_ref[winner][loser] = true;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k, n;
    if (!(std::cin >> k >> n)) {
        return 1;
    }

    std::cin.ignore();

    std::vector<std::vector<bool>> adj_matrix(k + 1, std::vector<bool>(k + 1, false));

    std::string line;
    for (int i = 0; i < n; ++i)
    {
        if (!std::getline(std::cin, line)) return 1;

        std::string part1_str, part2_str;
        size_t gt_pos = line.find('>');

        if (gt_pos == std::string::npos) {
            continue;
        }

        part1_str = line.substr(0, gt_pos);
        part2_str = line.substr(gt_pos + 1);

        std::vector<int> current_winners;
        std::vector<int> current_losers;

        size_t comma_pos_part1 = part1_str.find(',');
        if (comma_pos_part1 != std::string::npos) {
            std::stringstream ss_winners(part1_str);
            std::string p_str;
            std::getline(ss_winners, p_str, ',');
            current_winners.push_back(std::stoi(p_str));
            std::getline(ss_winners, p_str);
            current_winners.push_back(std::stoi(p_str));
            current_losers.push_back(std::stoi(part2_str));
        } else {
            current_winners.push_back(std::stoi(part1_str));
            std::stringstream ss_losers(part2_str);
            std::string p_str;
            std::getline(ss_losers, p_str, ',');
            current_losers.push_back(std::stoi(p_str));
            std::getline(ss_losers, p_str);
            current_losers.push_back(std::stoi(p_str));
        }

        for (int winner_node : current_winners) {
            for (int loser_node : current_losers) {
                add_edge_cpp(winner_node, loser_node, k, adj_matrix);
            }
        }
    }

    std::vector<std::vector<int>> adj(k + 1);
    std::vector<int> in_degree(k + 1, 0);

    for (int r = 1; r <= k; ++r)
    {
        for (int c = 1; c <= k; ++c)
        {
            if (adj_matrix[r][c]) {
                adj[r].push_back(c);
                in_degree[c]++;
            }
        }
    }

    std::queue<int> q_kahn;
    for (int i = 1; i <= k; ++i)
    {
        if (in_degree[i] == 0) {
            q_kahn.push(i);
        }
    }

    std::vector<int> result_list;
    result_list.reserve(k);

    while (!q_kahn.empty())
    {
        int u = q_kahn.front();
        q_kahn.pop();
        result_list.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q_kahn.push(v);
            }
        }
    }

    if (result_list.size() == static_cast<size_t>(k)) {
        for (size_t i = 0; i < result_list.size(); ++i) 
        {
            std::cout << result_list[i] << (i == result_list.size() - 1 ? "" : " ");
        }

        std::cout << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}