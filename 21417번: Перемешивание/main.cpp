//=====================================================================
//   21417번:    Перемешивание                   
//   @date:   2024-10-18              
//   @link:   https://www.acmicpc.net/problem/21417  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string deck;
	cin >> deck;

	int k;

	cin >> k;

	while (k--) {
		string left, right;
		bool isLeft = true;

		for (int i = deck.size() - 1; i >= 0; i--) {
			if (isLeft) left += deck[i];
			else right += deck[i];
			isLeft = !isLeft;
		}

		deck = right + left;
	}

	cout << deck;

	return 0;
}