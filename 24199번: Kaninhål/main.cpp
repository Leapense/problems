//=====================================================================
//   24199번:    Kaninhål                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/24199  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> final_order(N);
	for (auto &x : final_order) cin >> x;
	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {
			for (int d3 = 1; d3 < N; d3++) {
				vector<int> current_order;

				for (int i = N; i >= 1; i--) current_order.push_back(i);
				vector<int> depths = {d1, d2, d3};

				for (auto d : depths) {
					vector<int> last_d(current_order.end() - d, current_order.end());

					reverse(last_d.begin(), last_d.end());
					vector<int> new_order = last_d;
					new_order.insert(new_order.end(), current_order.begin(), current_order.end() - d);
					current_order = new_order;
				}

				if (current_order == final_order) {
					cout << d1 << " " << d2 << " " << d3 << "\n";
					return 0;
				}
			}
		}
	}
}