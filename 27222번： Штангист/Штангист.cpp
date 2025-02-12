#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> training(n);
    for (int i = 0; i < n; i++)
    {
        cin >> training[i];
    }

    long long total_gain = 0;
    for (int i = 0; i < n; i++)
    {
        int morning, evening;
        cin >> morning >> evening;
        // 운동한 날이고 체중이 증가했을 경우에만 근육량 증가분을 더한다.
        if (training[i] == 1 && evening > morning)
        {
            total_gain += (evening - morning);
        }
    }

    cout << total_gain << "\n";

    return 0;
}