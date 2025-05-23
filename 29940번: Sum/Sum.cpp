#include <iostream>
#include <vector>

int main()
{
    int n, s;
    std::cin >> n >> s;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right)
    {
        int current_sum = a[left] + a[right];
        if (current_sum == s)
        {
            count++;
            left++;
            right--;
        }
        else if (current_sum < s)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    std::cout << count << std::endl;

    return 0;
}