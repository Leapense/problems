#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        string elements;
        cin >> elements;

        unordered_map<char, int> elem_index;
        for (int i = 0; i < n; ++i)
            elem_index[elements[i]] = i;

        vector<vector<char>> table(n, vector<char>(n));
        for (int i = 0; i < n; ++i)
        {
            string row;
            cin >> row;
            for (int j = 0; j < n; ++j)
            {
                table[i][j] = row[j];
            }
        }

        cout << "S = {";
        for (int i = 0; i < n; ++i)
        {
            cout << elements[i];
            if (i != n - 1)
                cout << ",";
        }
        cout << "}\n";
        cout << " #|" << elements << '\n';
        cout << " -+";
        for (int i = 0; i < n; ++i)
            cout << "-";
        cout << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << " " << elements[i] << "|";
            for (int j = 0; j < n; ++j)
                cout << table[i][j];
            cout << '\n';
        }
        cout << '\n';

        bool valid = true;
        char bad_x = 0, bad_y = 0, bad_z = 0, bad_result = 0;
        for (int i = 0; i < n && valid; ++i)
            for (int j = 0; j < n && valid; ++j)
            {
                char result = table[i][j];
                if (!elem_index.count(result))
                {
                    valid = false;
                    bad_x = elements[i];
                    bad_y = elements[j];
                    bad_result = result;
                }
            }
        if (!valid)
        {
            cout << "NOT A SEMIGROUP: " << bad_x << "#" << bad_y << " = " << bad_result
                 << "  WHICH IS NOT AN ELEMENT OF THE SET\n";
            cout << "------------------------------\n\n";
            continue;
        }

        bool assoc = true;
        for (int i = 0; i < n && assoc; ++i)
            for (int j = 0; j < n && assoc; ++j)
                for (int k = 0; k < n && assoc; ++k)
                {
                    char left = table[elem_index[table[i][j]]][k];
                    char right = table[i][elem_index[table[j][k]]];
                    if (left != right)
                    {
                        assoc = false;
                        bad_x = elements[i];
                        bad_y = elements[j];
                        bad_z = elements[k];
                    }
                }
        if (!assoc)
        {
            cout << "NOT A SEMIGROUP: (" << bad_x << "#" << bad_y << ")#" << bad_z
                 << " IS NOT EQUAL TO " << bad_x << "#(" << bad_y << "#" << bad_z << ")\n";
            cout << "------------------------------\n\n";
            continue;
        }

        bool commutative = true;
        for (int i = 0; i < n && commutative; ++i)
            for (int j = i + 1; j < n && commutative; ++j)
            {
                if (table[i][j] != table[j][i])
                {
                    commutative = false;
                    bad_x = elements[i];
                    bad_y = elements[j];
                }
            }

        if (commutative)
        {
            cout << "COMMUTATIVE SEMIGROUP\n";
        }
        else
        {
            cout << "SEMIGROUP BUT NOT COMMUTATIVE  (" << bad_x << "#" << bad_y
                 << " IS NOT EQUAL TO " << bad_y << "#" << bad_x << ")\n";
        }
        cout << "------------------------------\n\n";
    }

    return 0;
}