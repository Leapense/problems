#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int X;
    cin >> X;

    string line;
    cin >> line;

    int countM = 0, countW = 0;

    while (!line.empty())
    {
        bool admitted = false;

        char first = line.front();
        int newM = countM + (first == 'M' ? 1 : 0);
        int newW = countW + (first == 'W' ? 1 : 0);

        if (abs(newM - newW) <= X)
        {
            countM = newM;
            countW = newW;
            line.erase(line.begin());
            admitted = true;
        }
        else if (line.size() > 1)
        {
            char second = line[1];
            newM = countM + (second == 'M' ? 1 : 0);
            newW = countW + (second == 'W' ? 1 : 0);

            if (abs(newM - newW) <= X)
            {
                countM = newM;
                countW = newW;
                line.erase(line.begin() + 1);
                admitted = true;
            }
        }

        if (!admitted)
        {
            break;
        }
    }

    cout << (countM + countW) << endl;
    return 0;
}