#include "main.h"

namespace BSU
{
    void solve(std::istream &in, std::ostream &out)
    {
        int n, m, k;
        in >> n >> m >> k;

        int countYellowAlexey = 0;
        for (int i = 0; i < n; i++)
        {
            int color;
            in >> color;

            if (color == 0)
            {
                countYellowAlexey++;
            }
        }

        int countRedBoris = 0;
        for (int i = 0; i < m; i++)
        {
            int color;
            in >> color;

            if (color == 1)
            {
                countRedBoris++;
            }
        }

        for (int i = 0; i < k; i++)
        {
            int s;
            in >> s;
        }

        int score = std::abs(countYellowAlexey - countRedBoris);
        out << score;
    }
}

#ifndef UNIT_TESTS
int main()
{
    BSU::solve(std::cin, std::cout);
    return 0;
}
#endif