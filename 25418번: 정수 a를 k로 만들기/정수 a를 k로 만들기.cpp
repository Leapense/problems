#include <iostream>
#include <queue>
#include <unordered_map>

class Transformer
{
private:
    int A, K;

public:
    Transformer(int start, int target) : A(start), K(target) {}

    int minOperations()
    {
        std::queue<std::pair<int, int>> q;
        std::unordered_map<int, bool> visited;

        q.push({A, 0});
        visited[A] = true;

        while (!q.empty())
        {
            int current = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (current == K)
            {
                return steps;
            }

            if (current + 1 <= K && !visited[current + 1])
            {
                q.push({current + 1, steps + 1});
                visited[current + 1] = true;
            }

            if (current * 2 <= K && !visited[current * 2])
            {
                q.push({current * 2, steps + 1});
                visited[current * 2] = true;
            }
        }

        return -1;
    }
};

int main()
{
    int A, K;
    std::cin >> A >> K;
    Transformer transformer(A, K);
    std::cout << transformer.minOperations() << std::endl;

    return 0;
}