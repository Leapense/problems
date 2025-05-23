#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    for (int tc = 1; tc <= T; tc++)
    {
        string line;
        getline(cin, line);
        double P = -1, U = -1, I = -1;
        size_t pos = 0;

        while ((pos = line.find('=', pos)) != string::npos)
        {
            char type = line[pos - 1];
            pos++;
            size_t start = pos;
            while (pos < line.size() && (isdigit(line[pos]) || line[pos] == '.'))
                pos++;
            double value = stod(line.substr(start, pos - start));
            double factor = 1;
            if (pos < line.size())
            {
                if (line[pos] == 'm')
                {
                    factor = 0.001;
                    pos++;
                }
                else if (line[pos] == 'k')
                {
                    factor = 1000;
                    pos++;
                }
                else if (line[pos] == 'M')
                {
                    factor = 1000000;
                    pos++;
                }
            }

            value *= factor;
            if (type == 'P')
            {
                P = value;
            }
            else if (type == 'U')
            {
                U = value;
            }
            else if (type == 'I')
            {
                I = value;
            }
        }

        cout << "Problem #" << tc << "\n";
        cout << fixed << setprecision(2);
        if (P < 0)
            cout << "P=" << U * I << "W\n\n";
        else if (U < 0)
            cout << "U=" << P / I << "V\n\n";
        else if (I < 0)
            cout << "I=" << P / U << "A\n\n";
    }

    return 0;
}