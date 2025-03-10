/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8296                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8296                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 09:38:34 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

bool checkAscending(const vector<int> &arr)
{
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            cnt++;
    }
    if (arr[n - 1] > arr[0])
        cnt++;
    return cnt <= 1;
}

bool checkDescending(const vector<int> &arr)
{
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
            cnt++;
    }
    if (arr[n - 1] < arr[0])
        cnt++;
    return cnt <= 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (checkAscending(arr) || checkDescending(arr))
        cout << "TAK";
    else
        cout << "NIE";
    return 0;
}