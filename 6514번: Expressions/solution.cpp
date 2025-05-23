#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char value;
    int left;
    int right;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    string expr;
    while (T--)
    {
        cin >> expr;
        int n = expr.size();

        vector<Node> nodes;
        nodes.reserve(n);
        vector<int> stack_idx;
        stack_idx.reserve(n);

        for (char c : expr)
        {
            if (islower(c))
            {
                nodes.push_back({c, -1, -1});
                stack_idx.push_back((int)nodes.size() - 1);
            }
            else
            {
                int right = stack_idx.back();
                stack_idx.pop_back();
                int left = stack_idx.back();
                stack_idx.pop_back();
                nodes.push_back({c, left, right});
                stack_idx.push_back((int)nodes.size() - 1);
            }
        }

        int root = stack_idx.back();

        {
            vector<int> mirror_stack;
            mirror_stack.reserve(nodes.size());
            mirror_stack.push_back(root);

            while (!mirror_stack.empty())
            {
                int idx = mirror_stack.back();
                mirror_stack.pop_back();
                std::swap(nodes[idx].left, nodes[idx].right);
                if (nodes[idx].left != -1)
                {
                    mirror_stack.push_back(nodes[idx].left);
                }
                if (nodes[idx].right != -1)
                {
                    mirror_stack.push_back(nodes[idx].right);
                }
            }
        }
        vector<vector<char>> depth_groups;
        depth_groups.reserve(32);
        int max_depth = 0;
        {
            deque<pair<int, int>> q;
            q.emplace_back(root, 0);
            while (!q.empty())
            {
                auto [idx, d] = q.front();
                q.pop_front();
                if (d >= (int)depth_groups.size())
                    depth_groups.resize(d + 1);
                depth_groups[d].push_back(nodes[idx].value);
                max_depth = max(max_depth, d);
                if (nodes[idx].left != -1)
                    q.emplace_back(nodes[idx].left, d + 1);
                if (nodes[idx].right != -1)
                    q.emplace_back(nodes[idx].right, d + 1);
            }
        }

        string out;
        out.reserve(n);
        for (int d = max_depth; d >= 0; --d)
        {
            for (char c : depth_groups[d])
            {
                out.push_back(c);
            }
        }

        cout << out << "\n";
    }

    return EXIT_SUCCESS;
}