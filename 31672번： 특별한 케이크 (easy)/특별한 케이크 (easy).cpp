#include <iostream>
#include <vector>
using namespace std;

struct Testimony
{
    vector<int> S;
    int B;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dummy;
    getline(cin, dummy);

    int N;
    cin >> N;

    vector<Testimony> testimonies(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int M;
        cin >> M;
        testimonies[i].S.resize(M);

        for (int j = 0; j < M; j++)
        {
            cin >> testimonies[i].S[j];
        }

        cin >> testimonies[i].B;
    }

    vector<int> possibleCandidates;

    for (int culprit = 1; culprit <= N; culprit++)
    {
        bool valid = true;
        for (int i = 1; i <= N; i++)
        {
            bool contains = false;
            for (int num : testimonies[i].S)
            {
                if (num == culprit)
                {
                    contains = true;
                    break;
                }
            }
            if (i == culprit)
            {
                if (testimonies[i].B == 1)
                {
                    if (contains)
                    {
                        valid = false;
                        break;
                    }
                }
                else
                {
                    if (!contains)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            else
            {
                if (testimonies[i].B == 1)
                {
                    if (!contains)
                    {
                        valid = false;
                        break;
                    }
                }
                else
                {
                    if (contains)
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid)
        {
            possibleCandidates.push_back(culprit);
        }
    }

    if (possibleCandidates.empty())
    {
        cout << "swi";
    }
    else
    {
        for (int i = 0; i < possibleCandidates.size(); i++)
        {
            cout << possibleCandidates[i];

            if (i != possibleCandidates.size() - 1)
            {
                cout << " ";
            }
        }
    }

    return 0;
}