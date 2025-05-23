#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> results;
    string line;
    while (true)
    {
        vector<array<char, 5>> blocks;
        while (getline(cin, line) && line != "#")
        {
            array<char, 5> alloc = {' ', ' ', ' ', ' ', ' '};
            stringstream ss(line);
            string token;
            while (getline(ss, token, ','))
            {
                size_t pos = token.find('/');
                char color = token[0];
                char waste = token[pos + 1];
                if (color == 'r')
                    alloc[0] = waste;
                else if (color == 'o')
                    alloc[1] = waste;
                else if (color == 'y')
                    alloc[2] = waste;
                else if (color == 'g')
                    alloc[3] = waste;
                else if (color == 'b')
                    alloc[4] = waste;
            }
            blocks.push_back(alloc);
        }
        if (blocks.empty())
            break;
        array<char, 5> wastes = {'P', 'G', 'S', 'A', 'N'};
        array<char, 5> bestCandidate;
        long long bestChanges = 1e9;
        sort(wastes.begin(), wastes.end());
        do
        {
            long long totalChanges = 0;
            for (auto &city : blocks)
                for (int i = 0; i < 5; i++)
                    if (city[i] != wastes[i])
                        totalChanges++;
            if (totalChanges < bestChanges)
            {
                bestChanges = totalChanges;
                bestCandidate = wastes;
            }
        } while (next_permutation(wastes.begin(), wastes.end()));
        string output = "r/";
        output.push_back(bestCandidate[0]);
        output += ",o/";
        output.push_back(bestCandidate[1]);
        output += ",y/";
        output.push_back(bestCandidate[2]);
        output += ",g/";
        output.push_back(bestCandidate[3]);
        output += ",b/";
        output.push_back(bestCandidate[4]);
        results.push_back(output);
    }
    for (auto &res : results)
        cout << res << "\n";
    return 0;
}
