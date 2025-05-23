#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<queue<string>> parrots(N);
    string line;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            parrots[i].push(word);
        }
    }

    getline(cin, line);
    istringstream iss(line);

    string word;
    while (iss >> word)
    {
        bool found = false;

        for (auto &q : parrots)
        {
            if (!q.empty() && q.front() == word)
            {
                q.pop();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Impossible" << "\n";
            return 0;
        }
    }

    for (auto &q : parrots)
    {
        if (!q.empty())
        {
            cout << "Impossible" << "\n";
            return 0;
        }
    }

    cout << "Possible" << "\n";

    return 0;
}