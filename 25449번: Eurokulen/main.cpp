//=====================================================================
//   25449번:    Eurokulen
//   @date:   2024-10-26
//   @link:   https://www.acmicpc.net/problem/25449
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int votes[1001][1001];
int total_points[1001];
int total_points2[1001];
vector<int> rankings;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		vector<int> K(N - 1);
		for (int j = 0; j < N - 1; ++j)
		{
			cin >> K[j];
		}
		for (int k = 0; k < N - 1; ++k)
		{
			int OPG_j = K[k];
			int points = N - 1 - k;
			votes[i][OPG_j] = points;
			total_points[OPG_j] += points;
		}
	}
	rankings.resize(N);
	for (int i = 0; i < N; ++i)
		rankings[i] = i + 1;
	sort(rankings.begin(), rankings.end(), [](int a, int b)
		 {
        if (total_points[a] != total_points[b])
            return total_points[a] > total_points[b];
        return a < b; });
	for (int i = 0; i < 3; ++i)
		cout << rankings[i] << (i < 2 ? " " : "\n");
	set<int> removed_votes_OPGs;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			if (votes[i][j] == votes[j][i] && votes[i][j] > 0)
			{
				removed_votes_OPGs.insert(i);
				removed_votes_OPGs.insert(j);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (removed_votes_OPGs.count(i) == 0)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (votes[i][j] > 0)
					total_points2[j] += votes[i][j];
			}
		}
	}
	sort(rankings.begin(), rankings.end(), [](int a, int b)
		 {
        if (total_points2[a] != total_points2[b])
            return total_points2[a] > total_points2[b];
        return a < b; });
	for (int i = 0; i < 3; ++i)
		cout << rankings[i] << (i < 2 ? " " : "\n");
	return 0;
}
