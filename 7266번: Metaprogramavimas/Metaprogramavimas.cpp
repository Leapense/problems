#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll LIM = 1000000000;
struct Test
{
    ll a, b;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Test> tests(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tests[i].a >> tests[i].b;
    }

    bool identity = true;
    for (int i = 0; i < N; i++)
    {
        if (tests[i].a != tests[i].b)
        {
            identity = false;
            break;
        }
    }

    if (identity)
    {
        cout << 1 << "\n"
             << "print\n";
        return 0;
    }

    bool addOnly = true;
    ll D = tests[0].b - tests[0].a;
    for (int i = 0; i < N; i++)
    {
        if (tests[i].b - tests[i].a != D)
        {
            addOnly = false;
            break;
        }
    }

    if (addOnly && D >= 0 && D < LIM)
    {
        cout << 2 << "\n"
             << "add " << D << "\n"
             << "print\n";
        return 0;
    }

    bool multOnly = true;
    ll M = -1;
    for (int i = 0; i < N; i++)
    {
        if (tests[i].a == 0)
        {
            if (tests[i].b != 0)
            {
                multOnly = false;
                break;
            }
        }
        else
        {
            if (M == -1)
            {
                M = tests[i].b / tests[i].a;
            }
            else
            {
                if (tests[i].b != tests[i].a * M)
                {
                    multOnly = false;
                    break;
                }
            }
            if (tests[i].b % tests[i].a != 0)
            {
                multOnly = false;
                break;
            }
        }
    }
    if (multOnly && M != -1 && M < LIM)
    {
        cout << 2 << "\n"
             << "multiply " << M << "\n"
             << "print\n";
        return 0;
    }
    if (multOnly && M == -1)
    {
        cout << 2 << "\n"
             << "multiply " << 0 << "\n"
             << "print\n";
        return 0;
    }

    ll candidateM = -1, candidateA = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (tests[i].a != tests[j].a)
            {
                ll num = tests[i].b - tests[j].b;
                ll den = tests[i].a - tests[j].a;
                if (den == 0)
                    continue;
                if (num % den != 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                candidateM = tests[i].b - tests[i].a * ((tests[i].b - tests[j].b) / den);
                candidateM = (tests[i].b - tests[j].b) / den;
                candidateA = tests[i].b - candidateM * tests[i].a;
                goto CHECK;
            }
        }
    }
CHECK:
    if (candidateM == -1)
    {
        candidateM = 0;
        candidateA = tests[0].b;
    }
    if (candidateM < 0 || candidateM >= LIM || candidateA < 0 || candidateA >= LIM)
    {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (tests[i].a * candidateM + candidateA != tests[i].b)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    if (candidateM == 1)
    {
        if (candidateA == 0)
        {
            cout << 1 << "\n"
                 << "print\n";
            return 0;
        }
        cout << 2 << "\n"
             << "add " << candidateA << "\n"
             << "print\n";
        return 0;
    }

    if (candidateA == 0)
    {
        cout << 2 << "\n"
             << "multiply " << candidateM << "\n"
             << "print\n";
    }

    cout << 3 << "\n"
         << "multiply " << candidateM << "\n"
         << "add " << candidateA << "\n"
         << "print\n";
    return 0;
}