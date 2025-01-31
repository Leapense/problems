#include <bits/stdc++.h>
using namespace std;

// Maximum possible primes up to 1000 is 168
const int MAX_PRIMES = 168;

// Global memoization tables and computed flags
bool memo0_table[170][170][170];
bool memo1_table[170][170][170];
bool computed0_table[170][170][170];
bool computed1_table[170][170][170];

// Recursive function to determine if current player can win
bool canWin(int t, int j, int b, int turn)
{
    if (turn == 0)
    { // Yongtae's turn
        if (computed0_table[t][j][b])
            return memo0_table[t][j][b];
        computed0_table[t][j][b] = true;
        // Try all possible moves for Yongtae
        // Move from S_T
        if (t > 0)
        {
            if (!canWin(t - 1, j, b, 1))
            {
                memo0_table[t][j][b] = true;
                return true;
            }
        }
        // Move from S_B
        if (b > 0)
        {
            if (!canWin(t, j, b - 1, 1))
            {
                memo0_table[t][j][b] = true;
                return true;
            }
        }
        // If no winning move found
        memo0_table[t][j][b] = false;
        return false;
    }
    else
    { // Yujin's turn
        if (computed1_table[t][j][b])
            return memo1_table[t][j][b];
        computed1_table[t][j][b] = true;
        // Try all possible moves for Yujin
        // Move from S_J
        if (j > 0)
        {
            if (!canWin(t, j - 1, b, 0))
            {
                memo1_table[t][j][b] = true;
                return true;
            }
        }
        // Move from S_B
        if (b > 0)
        {
            if (!canWin(t, j, b - 1, 0))
            {
                memo1_table[t][j][b] = true;
                return true;
            }
        }
        // If no winning move found
        memo1_table[t][j][b] = false;
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Sieve of Eratosthenes to find primes up to 1000
    vector<bool> is_prime(1001, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= 1000; p++)
    {
        if (is_prime[p])
        {
            for (int multiple = p * p; multiple <= 1000; multiple += p)
            {
                is_prime[multiple] = false;
            }
        }
    }

    // Read Yongtae's range
    int A, B;
    cin >> A >> B;
    vector<int> S_yongtae;
    for (int num = A; num <= B; num++)
    {
        if (is_prime[num])
            S_yongtae.push_back(num);
    }

    // Read Yujin's range
    int C, D;
    cin >> C >> D;
    vector<int> S_yujin;
    for (int num = C; num <= D; num++)
    {
        if (is_prime[num])
            S_yujin.push_back(num);
    }

    // Categorize primes into S_T, S_J, S_B
    set<int> set_yongtae(S_yongtae.begin(), S_yongtae.end());
    set<int> set_yujin(S_yujin.begin(), S_yujin.end());

    vector<int> S_T; // Only Yongtae can call
    vector<int> S_J; // Only Yujin can call
    vector<int> S_B; // Both can call

    for (auto p : set_yongtae)
    {
        if (set_yujin.find(p) != set_yujin.end())
        {
            S_B.push_back(p);
        }
        else
        {
            S_T.push_back(p);
        }
    }
    for (auto p : set_yujin)
    {
        if (set_yongtae.find(p) == set_yongtae.end())
        {
            S_J.push_back(p);
        }
    }

    int t = S_T.size();
    int j = S_J.size();
    int b = S_B.size();

    // Initialize computed flags to false
    memset(computed0_table, 0, sizeof(computed0_table));
    memset(computed1_table, 0, sizeof(computed1_table));

    // Determine the winner starting with Yongtae's turn
    bool yongtae_wins = canWin(t, j, b, 0);

    if (yongtae_wins)
    {
        cout << "yt";
    }
    else
    {
        cout << "yj";
    }

    return 0;
}
