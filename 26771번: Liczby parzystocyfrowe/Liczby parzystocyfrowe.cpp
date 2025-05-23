#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    unsigned long long N;
    cin >> N;
    unsigned long long power = 1;
    int d = 0;
    while (power < N + 1)
    {
        d++;
        power *= 5;
    }
    unsigned long long pow_d_1 = 1;
    for (int i = 1; i < d; i++)
    {
        pow_d_1 *= 5;
    }
    unsigned long long prev = pow_d_1 - 1;
    unsigned long long k = N - prev;
    unsigned long long offset = k - 1;
    unsigned long long first_index = offset / pow_d_1;
    vector<char> firstDigits = {'2', '4', '6', '8'};
    string result;
    result.push_back(firstDigits[first_index]);
    offset %= pow_d_1;
    vector<char> mapping = {'0', '2', '4', '6', '8'};
    if (d - 1 > 0)
    {
        string tail(d - 1, '0');
        for (int i = d - 2; i >= 0; i--)
        {
            tail[i] = mapping[offset % 5];
            offset /= 5;
        }
        result += tail;
    }
    cout << result;
    return 0;
}