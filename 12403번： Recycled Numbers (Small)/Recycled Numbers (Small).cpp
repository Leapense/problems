#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int A, B;
        cin >> A >> B;
        int count = 0;
        for (int n = A; n < B; n++)
        {
            string s = to_string(n);
            int len = s.size();
            set<int> seen;

            for (int i = 1; i < len; i++)
            {
                string rotated = s.substr(i) + s.substr(0, i);
                if (rotated[0] == '0')
                    continue;
                int m = stoi(rotated);
                if (n < m && m <= B)
                    seen.insert(m);
            }
            count += seen.size();
        }

        cout << "Case #" << t << ": " << count << "\n";
    }

    return 0;
}