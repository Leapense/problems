//=====================================================================
//   18100번:    Думский регламент                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/18100  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int K;
	cin >> K;

	vector<char> stack;
	bool valid = true;

	while (K--) {
		string action;
		char x;

		cin >> action >> x;

		if (action == "Add") {
			stack.push_back(x);
		} else if (action == "Vote") {
			if (stack.empty() || stack.back() != x) {
				valid = false;
				break;
			}
			stack.pop_back();
		}
	}

	if (valid && stack.empty()) cout << "Yes";
	else cout << "No";

	return 0;
}