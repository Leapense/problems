#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, double> mass;
    string element;

    double m;

    for (int i = 0; i < n; i++)
    {
        cin >> element >> m;
        mass[element] = m;
    }

    string compound;
    cin >> compound;

    double total = 0.0;

    for (int i = 0; i < compound.size();)
    {
        string sym;
        sym.push_back(compound[i++]);
        if (i < compound.size() && islower(compound[i]))
        {
            sym.push_back(compound[i++]);
        }

        int num = 0;
        while (i < compound.size() && isdigit(compound[i]))
        {
            num = num * 10 + (compound[i] - '0');
            i++;
        }

        if (num == 0)
            num = 1;
        total += mass[sym] * num;
    }

    cout << fixed << setprecision(6) << total << "\n";
    return 0;
}