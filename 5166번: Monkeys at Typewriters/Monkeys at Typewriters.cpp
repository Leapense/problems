#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    for (int dataSet = 1; dataSet <= K; dataSet++)
    {
        int n, m;
        long double s;
        cin >> n >> m >> s;

        map<char, long double> prob;
        for (int i = 0; i < m; i++)
        {
            char c;
            long double p;
            cin >> c >> p;
            prob[c] = p;
        }

        long double answer = 0.0;
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            long double wordProb = 1.0;
            for (char c : word)
            {
                wordProb *= prob[c];
            }
            wordProb *= s;
            answer += wordProb;
        }

        cout << "Data Set " << dataSet << ":\n";
        cout << uppercase << setprecision(4) << scientific << (long double)answer << "\n\n";
    }

    return 0;
}