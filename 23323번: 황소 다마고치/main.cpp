#include <iostream>
#include <bit>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        unsigned long long n, m;
        cin >> n >> m;

        unsigned long long days_without_food = std::bit_width(n);
        unsigned long long answer = days_without_food + m;

        cout << answer << "\n";
    }

    return 0;
}
