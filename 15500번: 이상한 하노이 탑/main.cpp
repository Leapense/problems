#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> peg1, peg2, peg3;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        peg1.push_back(arr[i]);
    }
    vector<pair<int, int>> moves;
    for (int d = N; d >= 1; d--)
    {
        bool inPeg1 = false;
        for (int x : peg1)
        {
            if (x == d)
            {
                inPeg1 = true;
                break;
            }
        }
        if (inPeg1)
        {
            while (peg1.back() != d)
            {
                int top = peg1.back();
                peg1.pop_back();
                peg2.push_back(top);
                moves.push_back({1, 2});
            }
            peg1.pop_back();
            peg3.push_back(d);
            moves.push_back({1, 3});
        }
        else
        {
            while (peg2.back() != d)
            {
                int top = peg2.back();
                peg2.pop_back();
                peg1.push_back(top);
                moves.push_back({2, 1});
            }
            peg2.pop_back();
            peg3.push_back(d);
            moves.push_back({2, 3});
        }
    }
    cout << moves.size() << "\n";
    for (auto &mv : moves)
        cout << mv.first << " " << mv.second << "\n";
    return 0;
}
