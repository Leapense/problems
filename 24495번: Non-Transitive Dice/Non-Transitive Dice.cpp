#include <bits/stdc++.h>
using namespace std;

class Die
{
public:
    int faces[4];
    Die() {}
    Die(int a, int b, int c, int d)
    {
        faces[0] = a;
        faces[1] = b;
        faces[2] = c;
        faces[3] = d;
    }
};

bool beats(const Die &X, const Die &Y)
{
    int winX = 0, winY = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (X.faces[i] > Y.faces[j])
                winX++;
            else if (X.faces[i] < Y.faces[j])
                winY++;
        }
    return winX > winY;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a1, a2, a3, a4, b1, b2, b3, b4;
        cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4;
        Die A(a1, a2, a3, a4);
        Die B(b1, b2, b3, b4);
        bool possible = false;
        for (int c1 = 1; c1 <= 10 && !possible; c1++)
            for (int c2 = 1; c2 <= 10 && !possible; c2++)
                for (int c3 = 1; c3 <= 10 && !possible; c3++)
                    for (int c4 = 1; c4 <= 10 && !possible; c4++)
                    {
                        Die C(c1, c2, c3, c4);
                        bool cond1 = beats(A, B) && beats(B, C) && beats(C, A);
                        bool cond2 = beats(A, C) && beats(C, B) && beats(B, A);
                        if (cond1 || cond2)
                        {
                            possible = true;
                        }
                    }
        cout << (possible ? "yes" : "no") << '\n';
    }
}
