#include <bits/stdc++.h>
using namespace std;

class SequenceGenerator
{
public:
    void generate(int N)
    {
        vector<int> sequence;
        int start = 1;
        int difference = 2;

        for (int i = 0; i < N; i++)
        {
            sequence.push_back(start + i * difference);
        }

        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                cout << ' ';
            cout << sequence[i];
        }

        cout << '\n';
    }
};

int main()
{
    int N;
    cin >> N;
    SequenceGenerator sg;
    sg.generate(N);

    return 0;
}